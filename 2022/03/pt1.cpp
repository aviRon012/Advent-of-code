#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//#define int int64_t
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, L, R) for(int i = (L); i < (R); i++)

int expected = 157;

int getIntersection(string str1, string str2){
    FOR(c, 'a', 'z' + 1){
        if(str1.find(c) != string::npos &&
           str2.find(c) != string::npos)
            return c - 'a' + 1;
    }
    FOR(c, 'A', 'Z' + 1){
        if(str1.find(c) != string::npos &&
           str2.find(c) != string::npos)
            return c - 'A' + 27;
    }
    return -1;
}

int handleLines(vector<string> &lines){
    int sum = 0;
    for(auto &line: lines){
        sum += getIntersection(line.substr(0, line.length()/2), line.substr(line.length()/2));
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