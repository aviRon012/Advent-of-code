#include "aoc-utils.hpp"
#include <windows.h>
#include <iostream>
#include <fstream>
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

vector<string> FileToLines(const string &path)
{
    fstream file;
    file.open(path, ios::in);
    if(!file.is_open()){
        cout << "\33[31mCan't open file: " << path << "\33[39m\n";
        return {};
    }
    vector<string> lines;
    string line;
    while(getline(file, line)) lines.push_back(line);
    file.close();
    return lines;
}
vector<vector<string>> LinesToBlocks(const vector<string> &lines)
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

vector<vector<string>> LinesToElements(const vector<string> &lines)
{
    vector<vector<string>> lineVec;
    vector<string> elems;
    string elem;
    istringstream iss;
    for(auto &line: lines){
        iss.str(line);
        while(iss >> elem) elems.push_back(elem);
        lineVec.push_back(elems);
        elems = {};
        iss.clear();
    }
    return lineVec;
}

vector<string> SplitByDelimiter(string str, const string &delimiter)
{
    vector<string> segments;
    size_t pos;
    while((pos = str.find(delimiter)) != string::npos){
        segments.push_back(str.substr(0, pos));
        str.erase(0, pos + delimiter.size());
    }
    if(str.size()) segments.push_back(str);
    return segments;
}

static vector<string> muliSplit(vector<string> &strs, const string &delimiter)
{
    vector<string> segments;
    for(auto &str: strs){
        auto segs = SplitByDelimiter(str, delimiter);
        for(auto &seg: segs){
            segments.push_back(seg);
        }
    }
    return segments;
}

vector<string> SplitByDelimiters(string str, const vector<string> &delimiters)
{
    vector<string> segments{str};
    for(auto &delim: delimiters){
        segments = muliSplit(segments, delim);
    }
    return segments;
}

} //Aoc