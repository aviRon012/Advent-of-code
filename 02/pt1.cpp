#include "../clipboard.hpp"
#include <iostream>
#include <string>
using namespace std;

int getScore(char a, char b){
    char A = a - 'A', B = b - 'X';
    int score = B + 1;
    switch (((A - B) + 3) % 3){
        case 0:
        return score + 3;
        case 1:
        return score;
        case 2:
        return score + 6;
        default:
        cout << "err\n";
        return 0;
    }
}

int main(){
    string line;
    int totalScore = 0;
    while(getline(cin, line)){
        totalScore += getScore(line[0], line[2]);
    }
    cout << totalScore;
    copyToClipBoard(totalScore);
}