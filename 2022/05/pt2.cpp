#include "../../aoc-utils.hpp"
#include <iostream>
using namespace std;
using namespace Aoc;

string expected = "MCD";

string handleFile(const string &path){
    auto file = openFile(path);
    vector<string> start;
    string line;
    while(getline(file, line)){
        if(line.size() == 0) break;
        start.push_back(line);
    }
    int numOfPiles = (start.back().size() + 1) / 4;
    start.pop_back();
    vector<string> piles(numOfPiles, "");
    while(start.size()){
        for(int i = 0; i < numOfPiles; i++){
            char c = start.back()[4 * i + 1];
            if(c != ' ') piles[i].push_back(c);
        }
        start.pop_back();
    }
    string s1, s2, s3;
    int num, from, to;
    while(file >> s1 >> num >> s2 >> from >> s3 >> to){
        to--;
        from--;
        piles[to] += piles[from].substr(piles[from].size() - num);
        piles[from].erase(piles[from].size() - num);
    }
    string result;
    for(auto &pile: piles) result.push_back(pile.back());
    return result;
}

int main()
{
    string result = handleFile("example.txt");
    printResult(result, expected);
    result = handleFile("input.txt");
    cout << result;
    clipboard(result);
}