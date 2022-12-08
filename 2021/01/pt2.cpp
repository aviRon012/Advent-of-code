#include "../../aoc-utils.hpp"
#include <iostream>
#include <deque>
using namespace std;
using namespace Aoc;

string expected = "5";

string handleFile(const string &path){
    auto file = openFile(path);
    deque<int> nums(3);
    file >> nums[0] >> nums[1] >> nums[2];
    int num, count = 0;
    while(file >> num) {nums.push_back(num); count += (num > nums[0]); nums.pop_front();}
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