#include "../../aoc-utils.hpp"
#include <iostream>
using namespace std;
using namespace Aoc;

string expected = "2";

bool isContained(int x0, int x1, int y0, int y1)
{
    if(x0 <= y0 && y1 <= x1) return true;
    if(y0 <= x0 && x1 <= y1) return true;
    return false;
}

string handleFile(const string &path)
{
    auto file = openFile(path);
    int count = 0, x0, x1, y0, y1;
    istringstream line;
    while(lineStreamNoPunctuation(file, line) >> x0 >> x1 >> y0 >> y1){
        count += isContained(x0, x1, y0, y1);
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