#include "../../aoc-utils.hpp"
#include <iostream>
#include <algorithm>
using namespace std;
using namespace Aoc;

string expected = "24000";

string handleFile(const string &path){
    auto file = openFile(path);
    istringstream line;
    vector<int> sums;
    while(file){
        int num, sum = 0;
        while(lineStream(file, line) >> num) sum += num;
        sums.push_back(sum);
    }
    return to_string(*max_element(ALL(sums)));
}

int main()
{
    string result = handleFile("example.txt");
    printResult(result, expected);
    result = handleFile("input.txt");
    cout << result;
    clipboard(result);
}