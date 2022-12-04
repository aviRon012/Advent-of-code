#include "../../aoc-utils.hpp"
#include <iostream>
using namespace std;
using namespace Aoc;

int expected = 12;

int getScore(char a, char b){
    a -= 'A';
    b -= 'X';
    static const int scores[3][3]{
        {3,4,8},
        {1,5,9},
        {2,6,7}
    };
    return scores[a][b];
}

int handleFile(const string &path){
    auto lines = fileToLines(path);
    int totalScore = 0;
    for(auto &line: lines){
        auto segs = splitByDelimiter(line, " ");
        totalScore += getScore(segs[0][0], segs[1][0]);
    }
    return totalScore;
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