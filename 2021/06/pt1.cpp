#include "../../aoc-utils.hpp"
#include <iostream>
using namespace std;
using namespace Aoc;

int expected = 5934;

int handleFile(const string &path){
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
    return sum;
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