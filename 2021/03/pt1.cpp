#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int expected = 198;

int intFromBinary(string &line, bool inverse = false){
    int result = 0;
    for(auto d: line){
        result *= 2;
        result += inverse ^ (d == '1');
    }
    return result;
}

char getMajority(vector<string> &lines, int index){
    int count = 0;
    for(auto &line: lines){
        if(line[index] == '1') count++;
        else count--;
    }
    return (count > 0) ? '1' : '0';
}

int handleLines(vector<string> &lines){
    int len = lines[0].length();
    string majorityBits;
    for(int i = 0; i < len; i++){
        majorityBits.push_back(getMajority(lines, i));
    }
    int gamma = intFromBinary(majorityBits);
    int epsilon = intFromBinary(majorityBits, true);
    return gamma * epsilon;
}

int handleFile(const string &path){
    fstream file;
    file.open(path, ios::in);
    if(!file.is_open()){
        cout << "\33[31mCan't open file: " << path << "\33[39m\n";
        return -1;
    }
    vector<string> lines;
    string line;
    while(getline(file, line)) lines.push_back(line);
    file.close();
    return handleLines(lines);
}

void clipboard(int64_t num){
    string str = to_string(num);
    const size_t len = str.length() + 1;
    HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, len);
    memcpy(GlobalLock(hMem), str.c_str(), len);
    GlobalUnlock(hMem);
    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);
    CloseClipboard();
}

int main()
{
    int result;
    result = handleFile("example.txt");
    cout << result;
    if(result == expected){
        cout << " \33[32m[OK]\33[39m\n";
    }else{
        cout << " != " << expected << " \33[31m[FAIL]\33[39m\n";
    }
    result = handleFile("input.txt");
    cout << result;
    clipboard(result);
}