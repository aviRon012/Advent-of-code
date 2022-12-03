#include "../../aoc-utils.hpp"
#include <iostream>
using namespace std;
using namespace Aoc;

int expected = 150;

int handleFile(const string &path){
    auto lines = FileToLines(path);
    auto elems = LinesToElements(lines);
    int x = 0, y = 0;
    for(auto &line: elems){
        int num = stoi(line[1]);
        switch(line[0][0]){
            case 'u':
                y -= num;
                break;
            case 'd':
                y += num;
                break;
            case 'f':
                x += num;
        }
    }
    return x * y;
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
    clipboard(to_string(result));
}