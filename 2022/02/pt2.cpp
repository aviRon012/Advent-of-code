#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int expected = 12;

int getScore(char a, char b){
    a -= 'A';
    b -= 'X';
    static const int scores[3][3]{
        {3,4,8},
        {1,5,9},
        {2,6,7}
    };
    return scores[a][b];
}

int handleLines(vector<string> &lines){
    int totalScore = 0;
    for(auto &line: lines){
        totalScore += getScore(line[0], line[2]);
    }
    return totalScore;
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