#include "../../aoc-utils.hpp"
#include <iostream>
using namespace std;
using namespace Aoc;

string expected = "24000";

string handleFile(const string &path){
    auto file = openFile(path);
    istringstream line;
    int max = 0;
    while(file){
        int num, sum = 0;
        while(lineStream(file, line) >> num) sum += num;
        max = (sum > max) ? sum : max;
    }
    return to_string(max);
}

int main()
{
    string result = handleFile("example.txt");
    printResult(result, expected);
    result = handleFile("input.txt");
    cout << result;
    clipboard(result);
}