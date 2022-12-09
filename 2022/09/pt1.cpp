#include "../../aoc-utils.hpp"
#include <iostream>
#include <set>
#include <map>
using namespace std;
using namespace Aoc;
using position = pair<int, int>;

string expected = "13";

bool far(position &H, position &T)
{
    return (abs(H.first - T.first) >= 2 || abs(H.second - T.second) >= 2);
}

string handleFile(const string &path)
{
    auto file = openFile(path);
    set<position> positions;
    position H{0,0}, T{0,0};
    map<char, position> directions = {{'R',{1,0}}, {'L',{-1,0}}, {'U',{0,1}}, {'D',{0,-1}}};
    char direction;
    int num;
    while(file >> direction >> num) for(int i = 0; i < num; i++){
        position prev = H;
        H.first += directions[direction].first;
        H.second += directions[direction].second;
        if(far(H,T)) T = prev;
        positions.insert(T);
    }
    return to_string(positions.size());
}

int main()
{
    string result = handleFile("example.txt");
    printResult(result, expected);
    result = handleFile("input.txt");
    cout << result;
    clipboard(result);
}