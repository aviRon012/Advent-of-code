#include "../../aoc-utils.hpp"
#include <iostream>
#include <unordered_map>
using namespace std;
using namespace Aoc;

int expected = 5;

void order(int &a, int &b)
{
    if(b > a) return;
    int temp = a;
    a = b;
    b = temp;
}

void inc(unordered_map<int, unordered_map<int, int>> &coords, int x, int y)
{
    if(coords[x].find(y) == coords[x].end()) coords[x][y] == 0;
    coords[x][y]++;
}

int handleFile(const string &path){
    auto file = openFile(path);
    int x1, y1, x2, y2;
    unordered_map<int, unordered_map<int, int>> coords;
    istringstream line;
    while(lineStreamNoPunctuation(file, line) >> x1 >> y1 >> x2 >> y2){
        if(x1 == x2){
            order(y1, y2);
            for(int i = y1; i <= y2; i++) inc(coords, x1, i);
            continue;
        }
        if(y1 == y2){
            order(x1, x2);
            for(int i = x1; i <= x2; i++) inc(coords, i, y1);
        }
    }
    int count = 0;
    for(auto &[x,m]: coords) for(auto &[y,n]: m) count += (n >= 2);
    return count;
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