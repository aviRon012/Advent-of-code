#include "../../aoc-utils.hpp"
#include <iostream>
using namespace std;
using namespace Aoc;

string expected = ""; //TODO initialize

string &handleFile(const string &path){
    auto file = openFile(path);
    //TODO solve
    //return to_string(...);
}

int main()
{
    string result = handleFile("example.txt");
    printResult(result, expected);
    result = handleFile("input.txt");
    cout << result;
    clipboard(result);
}