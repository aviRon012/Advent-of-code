#include "../../aoc-utils.hpp"
#include <iostream>
#include <map>
using namespace std;
using namespace Aoc;

string expected = "5";

void order(int &a, int &b)
{
    if(b > a) return;
    int temp = a;
    a = b;
    b = temp;
}

string handleFile(const string &path){
    auto file = openFile(path);
    int x1, y1, x2, y2;
    map<int, map<int, int>> coords;
    istringstream line;
    while(lineStreamNoPunctuation(file, line) >> x1 >> y1 >> x2 >> y2){
        if(x1 == x2){
            order(y1, y2);
            for(int i = y1; i <= y2; i++) coords[x1][i]++;
            continue;
        }
        if(y1 == y2){
            order(x1, x2);
            for(int i = x1; i <= x2; i++) coords[i][y1]++;
        }
    }
    int count = 0;
    for(auto &[x,m]: coords) for(auto &[y,n]: m) count += (n >= 2);
    return to_string(count);
}

int main()
{
    string result = handleFile("example.txt");
    printResult(result, expected);
    result = handleFile("input.txt");
    cout << result;
    clipboard(result);
}