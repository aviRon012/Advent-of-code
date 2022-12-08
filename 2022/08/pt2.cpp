#include "../../aoc-utils.hpp"
#include <iostream>
using namespace std;
using namespace Aoc;

string expected = "8"; //TODO initialize

template<int n>
string handleFile(const string &path){
    auto file = openFile(path);
    vector<string> trees;
    string line;
    while(getline(file, line)) trees.push_back(line);
    int max = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
        char hight = trees[i][j];
        int l = 0, r = 0, u = 0, d = 0;
        for(int ii = i - 1; ii >= 0; ii--) {u++; if(trees[ii][j] >= hight) break;}
        for(int ii = i + 1; ii < n; ii++) {d++; if(trees[ii][j] >= hight) break;}
        for(int jj = j - 1; jj >= 0; jj--) {l++; if(trees[i][jj] >= hight) break;}
        for(int jj = j + 1; jj < n; jj++) {r++; if(trees[i][jj] >= hight) break;}
        int score = l*r*u*d;
        max = (score > max) ? score : max;
    }
    return to_string(max);
}

int main()
{
    string result = handleFile<5>("example.txt");
    printResult(result, expected);
    result = handleFile<99>("input.txt");
    cout << result;
    clipboard(result);
}