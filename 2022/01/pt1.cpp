#include "../../aoc-utils.hpp"
#include <iostream>
#include <algorithm>
using namespace std;
using namespace Aoc;

int expected = 24000;

int handleFile(const string &path){
    auto file = openFile(path);
    istringstream line;
    vector<int> sums;
    while(file){
        int num, sum = 0;
        while(lineStream(file, line) >> num) sum += num;
        sums.push_back(sum);
    }
    sort(ALL(sums), greater<int>());
    return sums[0];
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