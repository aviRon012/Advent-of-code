#include "../../aoc-utils.hpp"
#include <iostream>
#include <array>
using namespace std;
using namespace Aoc;

string expected = "1924";

bool ckeckForWin(array<array<int, 5>, 5> &board, int i, int j)
{
    bool res = true;
    for(int k = 0; k < 5; k++){
        if(board[i][k] != -1){
            res = false;
            break;
        }
    }
    if(res) return true;
    res = true;
    for(int k = 0; k < 5; k++){
        if(board[k][j] != -1){
            res = false;
            break;
        }
    }
    return res;
}

bool updateBoard(array<array<int, 5>, 5> &board, int num)
{
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(board[i][j] == num){
                board[i][j] = -1;
                return ckeckForWin(board, i, j);
            }
        }
    }
    return false;
}

string evalWin(array<array<int, 5>, 5> &board, int num)
{
    int sum = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(board[i][j] >= 0) sum += board[i][j];
        }
    }
    return to_string(sum * num);
}

string handleFile(const string &path)
{
    auto file = openFile(path);
    vector<int> nums;
    istringstream line;
    int num;
    lineStreamNoPunctuation(file, line);
    while(line >> num) nums.push_back(num);
    vector<array<array<int, 5>, 5> > boards;
    array<array<int, 5>, 5> board;
    while(file){
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                file >> board[i][j];
            }
        }
        if(file) boards.push_back(board);
    }
    for(auto &num: nums){
        for(auto it = boards.begin(); it != boards.end(); it++){
            if(updateBoard(*it, num)){
                if(boards.size() == 1) return evalWin(*it, num);
                boards.erase(it--);
            }
        }
    }
    return "";
}

int main()
{
    string result = handleFile("example.txt");
    printResult(result, expected);
    result = handleFile("input.txt");
    cout << result;
    clipboard(result);
}