#include "../../clipboard.hpp"
#include <iostream>
#include <string>
using namespace std;

int getScore(char a, char b){
    static const int scores[3][3]{
        {3,4,8},
        {1,5,9},
        {2,6,7}
    };
    return scores[a][b];
}

int main(){
    string line;
    int totalScore = 0;
    while(getline(cin, line)){
        totalScore += getScore(line[0] - 'A', line[2] - 'X');
    }
    cout << totalScore;
    copyToClipBoard(totalScore);
}