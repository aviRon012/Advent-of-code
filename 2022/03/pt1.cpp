#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int expected = 157;

int handleLines(vector<string> &lines){
    int sum = 0;
    for(auto &line: lines){
        int half = line.length()/2;
        string str1 = line.substr(0, half);
        string str2 = line.substr(half, line.length());

        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        string intersection;
        set_intersection(str1.begin(), str1.end(), str2.begin(), str2.end(), back_inserter(intersection));
        if(intersection[0] >= 'a') sum += (intersection[0] - 'a' + 1);
        else sum += (intersection[0] - 'A' + 27);
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