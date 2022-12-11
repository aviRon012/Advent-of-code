#include "../../aoc-utils.hpp"
#include <iostream>
using namespace std;
using namespace Aoc;

string expected = "##..##..##..##..##..##..##..##..##..##..\n"
                  "###...###...###...###...###...###...###.\n"
                  "####....####....####....####....####....\n"
                  "#####.....#####.....#####.....#####.....\n"
                  "######......######......######......####\n"
                  "#######.......#######.......#######.....\n";

string pixel(int cycle, int reg)
{
    string res;
    if(abs((cycle-1) % 40 - reg) <= 1) res = "#";
    else res = '.';
    if(cycle % 40 == 0) res += '\n';
    return res;
}

string handleFile(const string &path)
{
    auto file = openFile(path);
    string output = "", instruction;
    int reg = 1, cycle = 0, num;
    while(file >> instruction){
        if(instruction == "noop"){
            output += pixel(++cycle, reg);
        }else{
            output += pixel(++cycle, reg);
            output += pixel(++cycle, reg);
            file >> num;
            reg += num;
        }
    }
    return output;
}

int main()
{
    string result = handleFile("example.txt");
    printResult(result, expected);
    result = handleFile("input.txt");
    cout << result;
}