#include "../../aoc-utils.hpp"
#include <iostream>
using namespace std;
using namespace Aoc;

string expected = "26";

fstream &ignoreStart(fstream &file)
{
    string s;
    for(int i = 0; i < 11; i++) file >> s;
    return file;
}

string handleFile(const string &path)
{
    auto file = openFile(path);
    string s;
    int count = 0;
    while(ignoreStart(file)){
        for(int i: {0,1,2,3}){
            file >> s;
            if(s.size() != 5 && s.size() != 6) count++;
        }
    }
    return to_string(count);
}

int main()
{
    string result = handleFile("example.txt");
    printResult(result, expected);
    result = handleFile("input.txt");
    cout << result;
    clipboard(result);
}