#include "../../aoc-utils.hpp"
#include <iostream>
using namespace std;
using namespace Aoc;

string expected = "900";

string handleFile(const string &path){
    auto file = openFile(path);
    int aim = 0, deapth = 0, horizontal = 0, num;
    string direction;
    while(file >> direction >> num){
        switch(direction[0]){
            case 'u':
                aim -= num;
                break;
            case 'd':
                aim += num;
                break;
            case 'f':
                horizontal += num;
                deapth += num * aim;
        }
    }
    return to_string(horizontal * deapth);
}

int main()
{
    string result = handleFile("example.txt");
    printResult(result, expected);
    result = handleFile("input.txt");
    cout << result;
    clipboard(result);
}