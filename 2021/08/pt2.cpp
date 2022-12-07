#include "../../aoc-utils.hpp"
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;
using namespace Aoc;

string expected = "61229";

int interSz(string &str1, string &str2)
{
    string inter;
    set_intersection(ALL(str1), ALL(str2), back_inserter(inter));
    return inter.size();
}

bool getDigits(fstream &file, array<string, 10> &digits)
{
    vector<string> fives, sixes;
    string in;
    for(int i = 0; i < 10; i++){
        file >> in;
        sort(ALL(in));
        switch(in.size()){
            case 2: digits[1] = in; break;
            case 3: digits[7] = in; break;
            case 4: digits[4] = in; break;
            case 7: digits[8] = in; break;
            case 5: fives.push_back(in); break;
            default: sixes.push_back(in);
        }
    }
    if(!file) return false;
    for(int i = 0; i < 3; i++) if(interSz(digits[1], sixes[i]) == 1){
        digits[6] = sixes[i];
        sixes.erase(sixes.begin() + i);
    }
    if(interSz(digits[4], sixes[0]) == 4){
        digits[9] = sixes[0];
        digits[0] = sixes[1];
    }else{
        digits[9] = sixes[1];
        digits[0] = sixes[0];
    }
    for(int i = 0; i < 3; i++) if(interSz(digits[6] ,fives[i]) == 5){
        digits[5] = fives[i];
        fives.erase(fives.begin() + i);
    }
    if(interSz(digits[1], fives[0]) == 2){
        digits[3] = fives[0];
        digits[2] = fives[1];
    }else{
        digits[3] = fives[1];
        digits[2] = fives[0];
    }
    return true;
}

int getNum(fstream &file, array<string, 10> &digits)
{
    string in;
    file >> in;
    int num = 0;
    for(int i = 0; i < 4; i++){
        num *= 10;
        file >> in;
        sort(ALL(in));
        num += find(ALL(digits), in) - digits.begin();
    }
    return num;
}

string handleFile(const string &path){
    auto file = openFile(path);
    int sum = 0;
    array<string, 10> digits;
    while(getDigits(file, digits)) sum += getNum(file, digits);
    return to_string(sum);
}

int main()
{
    string result = handleFile("example.txt");
    printResult(result, expected);
    result = handleFile("input.txt");
    cout << result;
    clipboard(result);
}