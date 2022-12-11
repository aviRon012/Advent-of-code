#include "../../aoc-utils.hpp"
#include <iostream>
#include <algorithm>
using namespace std;
using namespace Aoc;
#define int int64_t
using Test = bool (*)(int);
using Action = int (*)(int);

string expected = "2713310158";

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

string testExample()
{
    vector<monkey> monkeys = {
        {{79, 98}, [](int n){return n * 19;}, [](int n){return n % 23 == 0;}, 2, 3},
        {{54, 65, 75, 74}, [](int n){return n + 6;}, [](int n){return n % 19 == 0;}, 2, 0},
        {{79, 60, 97}, [](int n){return n * n;}, [](int n){return n % 13 == 0;}, 1, 3},
        {{74}, [](int n){return n + 3;}, [](int n){return n % 17 == 0;}, 0, 1}
    };
    int lcm = 23 * 19 * 13 * 17;
    for(int i = 1; i <= 10'000; i++){
        for(auto &m: monkeys){
            m.inspected += m.items.size();
            for(auto n: m.items){
                int temp = m.action(n) % lcm;
                if(m.test(temp)) monkeys[m.t].items.push_back(temp);
                else monkeys[m.f].items.push_back(temp);
            }
            m.items = {};
        }
        /*if(i % 1000 == 0 || i==1 || i==20){
            for(auto &m: monkeys) cout << m.inspected << endl;
            cout << endl;
            for(auto &m: monkeys) {for(auto n: m.items) cout << n << ' '; cout << endl;}
            cout << endl;
        }*/
    }
    sort(ALL(monkeys), greater<monkey>());
    //for(auto &m: monkeys) cout << m.inspected << endl;
    return to_string(monkeys[0].inspected * monkeys[1].inspected);
}

string handleFile()
{
    vector<monkey> monkeys = {
        {{91, 58, 52, 69, 95, 54}, [](int n){return n * 13;}, [](int n){return n % 7 == 0;}, 1, 5},
        {{80, 80, 97, 84}, [](int n){return n*n;}, [](int n){return n % 3 == 0;}, 3, 5},
        {{86, 92, 71}, [](int n){return n+7;}, [](int n){return n % 2 == 0;}, 0, 4},
        {{96, 90, 99, 76, 79, 85, 98, 61}, [](int n){return n+4;},[](int n){return n%11 == 0;}, 7, 6},
        {{60, 83, 68, 64, 73}, [](int n){return n * 19;}, [](int n){return n % 17 == 0;}, 1, 0},
        {{96, 52, 52, 94, 76, 51, 57}, [](int n){return n+3;}, [](int n){return n%5 == 0;}, 7, 3},
        {{75}, [](int n){return n + 5;}, [](int n){return n%13==0;}, 4, 2},
        {{83,75}, [](int n){return n + 1;}, [](int n){return n % 19 == 0;}, 2, 6}
    };
    int lcm = 7 * 3 * 2 * 11 * 17 * 5 * 13 * 19;
    for(int i = 0; i < 10'000; i++){
        for(auto &m: monkeys){
            m.inspected += m.items.size();
            for(auto n: m.items){
                int temp = m.action(n) % lcm;
                if(m.test(temp)) monkeys[m.t].items.push_back(temp);
                else monkeys[m.f].items.push_back(temp);
            }
            m.items = {};
        }
    }
    sort(ALL(monkeys), greater<monkey>());
    //for(auto &m: monkeys) cout << m.inspected << endl;
    return to_string(monkeys[0].inspected * monkeys[1].inspected);
}

#undef int
int main()
{
    auto result = testExample();
    printResult(result, expected);
    result = handleFile();
    cout << result;
    clipboard(result);
}