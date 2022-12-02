#include "..\..\clipboard.hpp"
#include <string>
#include <iostream>
using namespace std;

int main(){
    string str;
    int x = 0, y = 0, num;
    while(cin >> str){
        cin >> num;
        switch(str[0]){
            case 'u':
                y -= num;
                break;
            case 'd':
                y += num;
                break;
            case 'f':
                x += num;
        }
    }
    int result = x * y;
    cout << result;
    copyToClipBoard(result);
}