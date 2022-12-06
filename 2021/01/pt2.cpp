#include "../../aoc-utils.hpp"
#include <iostream>
using namespace std;
using namespace Aoc;

string expected = "5";

string handleFile(const string &path){
    auto file = openFile(path);
    vector<int> nums;
    int num;
    while(file >> num) nums.push_back(num);
    int count = 0;
    for(int i = 3; i < nums.size(); i++) count += (nums[i] > nums[i - 3]);
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