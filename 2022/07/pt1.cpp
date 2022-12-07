#include "../../aoc-utils.hpp"
#include <iostream>
#include <map>
using namespace std;
using namespace Aoc;

string expected = "95437"; //TODO initialize

string initialPath(vector<string> pwd, int deapth){
    string path = "";
    for(int i = 0; i < deapth; i++) path += "/" + pwd[i];
    return path;
}

string handleFile(const string &path){
    auto file = openFile(path);
    string arg1 ,arg2, arg3;
    vector<string> pwd;
    map<string, int> dirs;
    while(file >> arg1){
        if(arg1 == "$"){
            file >> arg2;
            if(arg2 == "cd"){
                file >> arg3;
                if(arg3 == "/") pwd = {};
                else if(arg3 == "..") pwd.pop_back();
                else pwd.push_back(arg3);
            }else if(arg2 == "ls") continue;
        }else if(arg1 == "dir"){
            file >> arg2;
            continue;
        }else{
            int sz = stoi(arg1);
            for(int i = 0; i <= pwd.size(); i++) dirs[initialPath(pwd, i)] += sz;
            file >> arg2;
        }
    }
    int sum = 0;
    for(auto &[dir, size]: dirs) if(size <= 100000) sum += size;
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