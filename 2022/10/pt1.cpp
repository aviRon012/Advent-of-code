#include "../../aoc-utils.hpp"
#include <iostream>
using namespace std;
using namespace Aoc;

string expected = "13140";

int signalStrength(int cycle, int reg)
{
    if((cycle - 20) % 40 == 0) return reg * cycle;
    return 0;
}

string handleFile(const string &path)
{
    auto file = openFile(path);
    int num, reg = 1, total = 0, cycle = 0;
    string instruction;
    while(file >> instruction){
        if(instruction == "noop"){
            total += signalStrength(++cycle, reg);
        }else{
            total += signalStrength(++cycle, reg);
            total += signalStrength(++cycle, reg);
            file >> num;
            reg += num;
        }
    }
    return to_string(total);
}

int main()
{
    string result = handleFile("example.txt");
    printResult(result, expected);
    result = handleFile("input.txt");
    cout << result;
    clipboard(result);
}