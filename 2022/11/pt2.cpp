#include "../../aoc-utils.hpp"
#include <iostream>
#include <algorithm>
using namespace std;
using namespace Aoc;
using Action = int64_t (*)(int64_t);

string expected = "2713310158";

struct monkey
{
    vector<int64_t> items;
    Action action;
    int factor;
    int t;
    int f;
    int64_t inspected = 0;
    auto operator<=>(const monkey &other) const {return this->inspected <=> other.inspected;};
};

string handleFile(vector<monkey> &monkeys)
{
    int64_t lcm = 1;
    for(auto m: monkeys) lcm *= m.factor;
    for(int i = 0; i < 10'000; i++){
        for(auto &m: monkeys){
            m.inspected += m.items.size();
            for(auto n: m.items){
                int64_t temp = m.action(n) % lcm;
                if(temp % m.factor == 0) monkeys[m.t].items.push_back(temp);
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
    vector<monkey> example = {
        {{79, 98}, [](int64_t n){return n * 19;}, 23, 2, 3},
        {{54, 65, 75, 74}, [](int64_t n){return n + 6;}, 19, 2, 0},
        {{79, 60, 97}, [](int64_t n){return n * n;}, 13, 1, 3},
        {{74}, [](int64_t n){return n + 3;}, 17, 0, 1}
    };
    vector<monkey> input = {
        {{91, 58, 52, 69, 95, 54}, [](int64_t n){return n * 13;}, 7, 1, 5},
        {{80, 80, 97, 84}, [](int64_t n){return n*n;}, 3, 3, 5},
        {{86, 92, 71}, [](int64_t n){return n+7;}, 2, 0, 4},
        {{96, 90, 99, 76, 79, 85, 98, 61}, [](int64_t n){return n+4;}, 11, 7, 6},
        {{60, 83, 68, 64, 73}, [](int64_t n){return n * 19;}, 17, 1, 0},
        {{96, 52, 52, 94, 76, 51, 57}, [](int64_t n){return n+3;}, 5, 7, 3},
        {{75}, [](int64_t n){return n + 5;}, 13, 4, 2},
        {{83,75}, [](int64_t n){return n + 1;}, 19, 2, 6}
    };
    auto result = handleFile(example);
    printResult(result, expected);
    result = handleFile(input);
    cout << result;
    clipboard(result);
}