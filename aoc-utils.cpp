#include "aoc-utils.hpp"
#include <windows.h>
#include <iostream>
#include <sstream>
using namespace std;

namespace Aoc{

void clipboard(const string &str)
{
    const size_t len = str.length() + 1;
    HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, len);
    memcpy(GlobalLock(hMem), str.c_str(), len);
    GlobalUnlock(hMem);
    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);
    CloseClipboard();
}

fstream openFile(const string &path)
{
    fstream file;
    file.open(path, ios::in);
    if(!file.is_open()) cout << "\33[31mCan't open file: " << path << "\33[39m\n";
    return file;
}

vector<string> fileToLines(const string &path)
{
    auto file = openFile(path);
    if(!file.is_open()) return {};
    vector<string> lines;
    string line;
    while(getline(file, line)) lines.push_back(line);
    file.close();
    return lines;
}

vector<vector<string>> linesToBlocks(const vector<string> &lines)
{
    vector<vector<string>> blocks;
    vector<string> block;
    for(auto &line: lines){
        if(line.size()) block.push_back(line);
        else{
            blocks.push_back(block);
            block = {};
        }
    }
    if(lines.back().size()) blocks.push_back(block);
    return blocks;
}

vector<string> splitByDelimiter(string str, const string &delimiter)
{
    vector<string> segments;
    size_t pos;
    while((pos = str.find(delimiter)) != string::npos){
        if(pos) segments.push_back(str.substr(0, pos));
        str.erase(0, pos + delimiter.size());
    }
    if(str.size()) segments.push_back(str);
    return segments;
}

vector<string> splitByDelimiters(string str, const vector<string> &delimiters)
{
    vector<string> segments{str};
    for(auto &delim: delimiters){
        vector<string> temp{};
        for(auto &seg: segments){
            auto segs = splitByDelimiter(seg, delim);
            temp.insert(temp.end(), ALL(segs));
        }
        segments = temp;
    }
    return segments;
}

} //Aoc