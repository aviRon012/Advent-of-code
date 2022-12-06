#include "../../aoc-utils.hpp"
#include <iostream>
#include <algorithm>
using namespace std;
using namespace Aoc;

string expected = "45000";

string handleFile(const string &path){
    auto file = openFile(path);
    istringstream line;
    vector<int> sums;
    while(file){
        int num, sum = 0;
        while(lineStream(file, line) >> num) sum += num;
        sums.push_back(sum);
    }
    nth_element(sums.begin(), sums.begin() + 2, sums.end(), greater<int>());
    return to_string(sums[0] + sums[1] + sums[2]);
}

int main()
{
    string result = handleFile("example.txt");
    printResult(result, expected);
    result = handleFile("input.txt");
    cout << result;
    clipboard(result);
}