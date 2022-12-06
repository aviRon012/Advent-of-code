#include "../../aoc-utils.hpp"
#include <iostream>
using namespace std;
using namespace Aoc;

string expected = "4";

bool overlaps(int x0, int x1, int y0, int y1)
{
    return (x1 >= y0) && (y1 >= x0);
}

string handleFile(const string &path)
{
    auto file = openFile(path);
    int count = 0, x0, x1, y0, y1;
    istringstream line;
    while(lineStreamNoPunctuation(file, line) >> x0 >> x1 >> y0 >> y1){
        count += overlaps(x0, x1, y0, y1);
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