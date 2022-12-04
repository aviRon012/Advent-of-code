#include "../../aoc-utils.hpp"
#include <iostream>
using namespace std;
using namespace Aoc;

int expected = 15;

int getScore(char a, char b){
    a -= 'A';
    b -= 'X';
    static const int scores[3][3]{
        {4,8,3},
        {1,5,9},
        {7,2,6}
    };
    return scores[a][b];
}

int handleFile(const string &path){
    auto file = openFile(path);
    int totalScore = 0;
    char a, b;
    while(file >> a >> b){
        totalScore += getScore(a, b);
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