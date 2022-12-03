#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//#define int int64_t
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, L, R) for(int i = (L); i < (R); i++)

int expected = 230;

int intFromBinary(string str){
    int result = 0;
    for(auto d: str){
        result *= 2;
        result += (d =='1');
    }
    return result;
}

char getMajority(vector<string> &lines, int index, bool minority = false){
    int count = 0;
    for(auto &line: lines){
        if(line[index] == '1') count++;
        else count--;
    }
    return (count >= 0) ^ minority ? '1' : '0';
}

int getNumber(vector<string> &lines, bool minority = false){
    int len = sz(lines[0]), i;
    string majority;
    auto pred = [&i, &majority](string &line){return (line[i]) != majority[i];};
    for(i = 0; sz(lines) > 1; i++){
        majority = {};
        FOR(j, 0, len){
            majority.push_back(getMajority(lines, i, minority));
        }
        lines.erase(remove_if(ALL(lines), pred), lines.end());
    }
    return intFromBinary(lines[0]);
}

int handleLines(vector<string> &lines){
    auto copy = lines;
    int oxygen = getNumber(lines);
    int co2 = getNumber(copy, true);
    return oxygen * co2;
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

void clipboard(int num){
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