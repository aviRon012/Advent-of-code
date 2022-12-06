#include "../../aoc-utils.hpp"
#include <iostream>
using namespace std;
using namespace Aoc;

string expected = "15";

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

string handleFile(const string &path){
    auto file = openFile(path);
    int totalScore = 0;
    char a, b;
    while(file >> a >> b){
        totalScore += getScore(a, b);
    }
    return to_string(totalScore);
}

int main()
{
    string result = handleFile("example.txt");
    printResult(result, expected);
    result = handleFile("input.txt");
    cout << result;
    clipboard(result);
}