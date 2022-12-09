#include "../../aoc-utils.hpp"
#include <iostream>
#include <set>
#include <map>
using namespace std;
using namespace Aoc;
using position = pair<int, int>;

string expected = "36";

void drag(position &dragger, position &dragged)
{
    if (abs(dragged.first - dragger.first) > 1 ||
        abs(dragged.second - dragger.second) > 1)
    {
        if (dragged.first < dragger.first) dragged.first++;
        if (dragged.first > dragger.first) dragged.first--;
        if (dragged.second < dragger.second) dragged.second++;
        if (dragged.second > dragger.second) dragged.second--;
    }
}

string handleFile(const string &path)
{
    auto file = openFile(path);
    set<position> positions;
    position rope[10] = {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};
    map<char, position> directions = {{'R',{1,0}}, {'L',{-1,0}}, {'U',{0,1}}, {'D',{0,-1}}};
    char direction;
    int num;
    while(file >> direction >> num) for(int i = 0; i < num; i++){
        rope[0].first += directions[direction].first;
        rope[0].second += directions[direction].second;
        for(int i = 1; i < 10; i++) drag(rope[i-1], rope[i]);
        positions.insert(rope[9]);
    }
    return to_string(positions.size());
}

int main()
{
    string result = handleFile("example2.txt");
    printResult(result, expected);
    result = handleFile("input.txt");
    cout << result;
    clipboard(result);
}