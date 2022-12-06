#include "../../aoc-utils.hpp"
#include <iostream>
using namespace std;
using namespace Aoc;

string expected = "150";

string handleFile(const string &path){
    auto file = openFile(path);
    int x = 0, y = 0, num;
    string direction;
    while(file >> direction >> num){
        switch(direction[0]){
            case 'u':
                y -= num;
                break;
            case 'd':
                y += num;
                break;
            case 'f':
                x += num;
        }
    }
    return to_string(x * y);
}

int main()
{
    string result = handleFile("example.txt");
    printResult(result, expected);
    result = handleFile("input.txt");
    cout << result;
    clipboard(result);
}