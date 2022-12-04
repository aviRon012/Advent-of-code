#include "../../aoc-utils.hpp"
#include <iostream>
using namespace std;
using namespace Aoc;

int expected = 900;

int handleFile(const string &path){
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
    return horizontal * deapth;
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