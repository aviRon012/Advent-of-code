#include "../../aoc-utils.hpp"
#include <iostream>
using namespace std;
using namespace Aoc;

string expected = "5934";

string handleFile(const string &path){
    auto file = openFile(path);
    istringstream line;
    lineStreamNoPunctuation(file, line);
    int fish[9]{0};
    int days;
    while(line >> days) fish[days]++;
    for(int i = 0; i < 80; i++){
        int birthed = fish[0];
        for(int j = 0; j < 8; j++) fish[j] = fish[j+1];
        fish[6] += birthed;
        fish[8] = birthed;
    }
    int sum = 0;
    for(int i = 0; i < 9; i++) sum += fish[i];
    return to_string(sum);
}

int main()
{
    string result = handleFile("example.txt");
    printResult(result, expected);
    result = handleFile("input.txt");
    cout << result;
    clipboard(result);
}