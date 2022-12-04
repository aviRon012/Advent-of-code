#include "../../aoc-utils.hpp"
#include <iostream>
using namespace std;
using namespace Aoc;

int expected = 7;

int handleFile(const string &path){
    auto lines = fileToLines(path);
    vector<int> nums;
    for(auto &line: lines){
        nums.push_back(stoi(line));
    }
    int count = 0;
    for(int i = 1; i < nums.size(); i++){
        count += (nums[i] > nums[i - 1]);
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