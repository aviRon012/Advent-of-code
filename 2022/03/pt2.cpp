#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int expected = 70;

int getIntersection(string str1, string str2, string str3){
    for(char c = 'a'; c <= 'z'; c++){
        if(str1.find(c) != string::npos &&
           str2.find(c) != string::npos &&
           str3.find(c) != string::npos)
            return c - 'a' + 1;
    }
    for(char c = 'A'; c <= 'Z'; c++){
        if(str1.find(c) != string::npos &&
           str2.find(c) != string::npos &&
           str3.find(c) != string::npos)
            return c - 'A' + 27;
    }
    return -1;
}

int handleLines(vector<string> &lines){
    int sum = 0;
    for(int i = 0; i < lines.size(); i += 3){
        sum += getIntersection(lines[i], lines[i + 1], lines[i + 2]);
    }
    return sum;
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