#include "..\..\clipboard.hpp"
#include <string>
#include <iostream>
using namespace std;

int main(){
    string str;
    int aim = 0, deapth = 0, horizontal = 0, num;
    while(cin >> str){
        cin >> num;
        switch(str[0]){
            case 'u':
                aim -= num;
                break;
            case 'd':
                aim += num;
                break;
            case 'f':
                horizontal += num;
                deapth += (aim * num);
        }
    }
    int result = horizontal * deapth;
    cout << result;
    copyToClipBoard(result);
}