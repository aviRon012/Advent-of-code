#include "../../aoc-utils.hpp"
#include <iostream>
using namespace std;
using namespace Aoc;

int expected = 4;

bool overlaps(int x0, int x1, int y0, int y1)
{
    if(x1 < y0) return false;
    if(y1 < x0) return false;
    return true;
}

int handleFile(const string &path)
{
    auto lines = FileToLines(path);
    int x0, x1, y0, y1, count = 0, pos;
    for(auto &line: lines){
        x0 = stoi(line.substr(0 ,pos = line.find('-')));
        line.erase(0, pos + 1);
        x1 = stoi(line.substr(0 ,pos = line.find(',')));
        line.erase(0, pos + 1);
        y0 = stoi(line.substr(0 ,pos = line.find('-')));
        line.erase(0, pos + 1);
        y1 = stoi(line);
        count += overlaps(x0, x1, y0, y1);
    }
    return count;
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