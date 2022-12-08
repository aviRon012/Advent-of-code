#include "../../aoc-utils.hpp"
#include <iostream>
#include <bitset>
#include <array>
using namespace std;
using namespace Aoc;

string expected = "21";

template<int n>
string handleFile(const string &path){
    auto file = openFile(path);
    vector<string> trees;
    string line;
    while(getline(file, line)) trees.push_back(line);
    array<bitset<n>,n> vis;
    //for(int i = 0; i < n; i++) cout << vis[i] << endl; cout << endl;
    for(int i = 0; i < n; i++){
        char tallest = 0;
        for(int j = 0; j < n; j++) if(trees[i][j] > tallest){
            vis[i][j] = true;
            tallest = trees[i][j];
        }
    }
    //for(int i = 0; i < n; i++) cout << vis[i] << endl; cout << endl;
    for(int i = 0; i < n; i++){
        char tallest = 0;
        for(int j = n-1; j >= 0; j--) if(trees[i][j] > tallest){
            vis[i][j] = true;
            tallest = trees[i][j];
        }
    }
    //for(int i = 0; i < n; i++) cout << vis[i] << endl; cout << endl;
    for(int i = 0; i < n; i++){
        char tallest = 0;
        for(int j = 0; j < n; j++) if(trees[j][i] > tallest){
            vis[j][i] = true;
            tallest = trees[j][i];
        }
    }
    //for(int i = 0; i < n; i++) cout << vis[i] << endl; cout << endl;
    for(int i = 0; i < n; i++){
        char tallest = 0;
        for(int j = n-1; j >= 0; j--) if(trees[j][i] > tallest){
            vis[j][i] = true;
            tallest = trees[j][i];
        }
    }
    //for(int i = 0; i < n; i++) cout << vis[i] << endl; cout << endl;
    int count = 0;
    for(int i = 0; i < n; i++) count += vis[i].count();
    return to_string(count);
}

int main()
{
    string result = handleFile<5>("example.txt");
    printResult(result, expected);
    result = handleFile<99>("input.txt");
    cout << result;
    clipboard(result);
}