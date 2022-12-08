#include "../../aoc-utils.hpp"
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
using namespace Aoc;

string expected = "45000";

string handleFile(const string &path){
    auto file = openFile(path);
    istringstream line;
    vector<int> max3;
    for(int i: {0,1,2}){
        int num, sum = 0;
        while(lineStream(file, line) >> num) sum += num;
        max3.push_back(sum);
    }
    while(file){
        int num, sum = 0;
        while(lineStream(file, line) >> num) sum += num;
        max3.push_back(sum);
        sort(ALL(max3), greater<int>());
        max3.pop_back();
    }
    return to_string(reduce(ALL(max3)));
}

int main()
{
    string result = handleFile("example.txt");
    printResult(result, expected);
    result = handleFile("input.txt");
    cout << result;
    clipboard(result);
}