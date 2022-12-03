#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int expected = 70;

int handleLines(vector<string> &lines){
    int sum = 0;
    for(int i = 0; i < lines.size(); i += 3){
        sort(lines[i].begin(), lines[i].end());
        sort(lines[i+1].begin(), lines[i+1].end());
        string temp1;
        set_intersection(lines[i].begin(), lines[i].end(), lines[i+1].begin(), lines[i+1].end(), back_inserter(temp1));
        sort(temp1.begin(), temp1.end());
        sort(lines[i+2].begin(), lines[i+2].end());
        string temp2;
        set_intersection(temp1.begin(), temp1.end(), lines[i+2].begin(), lines[i+2].end(), back_inserter(temp2));
        if(temp2[0] >= 'a') sum += (temp2[0] - 'a' + 1);
        else sum += (temp2[0] - 'A' + 27);
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