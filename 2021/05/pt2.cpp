#include "../../aoc-utils.hpp"
#include <iostream>
#include <unordered_map>
using namespace std;
using namespace Aoc;

string expected = "12";

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void order(int &a, int &b)
{
    if(b > a) return;
    swap(a, b);
}

string handleFile(const string &path){
    auto file = openFile(path);
    int x1, y1, x2, y2;
    unordered_map<int, unordered_map<int, int>> coords;
    istringstream line;
    while(lineStreamNoPunctuation(file, line) >> x1 >> y1 >> x2 >> y2){
        if(x1 == x2){
            order(y1, y2);
            for(; y1 <= y2; y1++) coords[x1][y1]++;
            continue;
        }
        if(x1 >= x2){
            swap(x1, x2);
            swap(y1, y2);
        }
        if(y1 == y2){
            for(; x1 <= x2; x1++) coords[x1][y1]++;
            continue;
        }
        if(y1 - x1 == y2 - x2){
            for(; x1 <= x2; x1++, y1++) coords[x1][y1]++;
            continue;
        }
        if(x1 + y1 == x2 + y2){
            for(; x1 <= x2; x1++, y1--) coords[x1][y1]++;
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