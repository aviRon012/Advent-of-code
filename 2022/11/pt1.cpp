#include "../../aoc-utils.hpp"
#include <iostream>
#include <algorithm>
using namespace std;
using namespace Aoc;

using Test = bool (*)(int);
using Action = int (*)(int);

struct monkey
{
    vector<int> items;
    Action action;
    Test test;
    int t;
    int f;
    int inspected = 0;
    auto operator<=>(const monkey &other) const {return this->inspected <=> other.inspected;};
};


string handleFile()
{
    vector<monkey> monkeys = {
        {vector<int>{91, 58, 52, 69, 95, 54}, [](int n){return n * 13;}, [](int n){return n % 7 == 0;}, 1, 5},
        {vector<int>{80, 80, 97, 84}, [](int n){return n*n;}, [](int n){return n % 3 == 0;}, 3, 5},
        {vector<int>{86, 92, 71}, [](int n){return n+7;}, [](int n){return n % 2 == 0;}, 0, 4},
        {vector<int>{96, 90, 99, 76, 79, 85, 98, 61}, [](int n){return n+4;},[](int n){return n%11 == 0;}, 7, 6},
        {vector<int>{60, 83, 68, 64, 73}, [](int n){return n * 19;}, [](int n){return n % 17 == 0;}, 1, 0},
        {vector<int>{96, 52, 52, 94, 76, 51, 57}, [](int n){return n+3;}, [](int n){return n%5 == 0;}, 7, 3},
        {vector<int>{75}, [](int n){return n + 5;}, [](int n){return n%13==0;}, 4, 2},
        {vector<int>{83,75}, [](int n){return n + 1;}, [](int n){return n % 19 == 0;}, 2, 6}
    };
    for(int i = 0; i < 20; i++){
        for(auto &m: monkeys){
            m.inspected += m.items.size();
            for(auto n: m.items){
                int temp = m.action(n)/3;
                if(m.test(temp)) monkeys[m.t].items.push_back(temp);
                else monkeys[m.f].items.push_back(temp);
            }
            m.items = {};
        }
    }
    sort(ALL(monkeys), greater<monkey>());
    return to_string(monkeys[0].inspected * monkeys[1].inspected);
}

int main()
{
    auto result = handleFile();
    cout << result;
    clipboard(result);
}