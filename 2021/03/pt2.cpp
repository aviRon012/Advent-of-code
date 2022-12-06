#include "../../aoc-utils.hpp"
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;
using namespace Aoc;

int expected = 230;

template<int n>
bool majorityAtIndex(vector<bitset<n>> &bits, int index)
{
    int count = 0;
    for(auto &b: bits) count += b[index];
    return count >= bits.size() - count;
}

template<int n>
int handleFile(const string &path)
{
    auto file = openFile(path);
    bitset<n> in;
    vector<bitset<n>> bits;
    while(file >> in) bits.push_back(in);
    auto copy = bits;
    for(int i = n-1; bits.size() > 1; i--){
        bool b = majorityAtIndex<n>(bits, i);
        auto pred = [i, b](bitset<n> &bi){return bi[i] ^ b;};
        bits.erase(remove_if(ALL(bits), pred), bits.end());
    }
    int oxygen = bits[0].to_ulong();
    for(int i = n-1; copy.size() > 1; i--){
        bool b = !majorityAtIndex<n>(copy, i);
        auto pred = [i, b](bitset<n> &bi){return bi[i] ^ b;};
        copy.erase(remove_if(ALL(copy), pred), copy.end());
    }
    int co2 = copy[0].to_ulong();
    return oxygen * co2;
}

int main()
{
    int result;
    result = handleFile<5>("example.txt");
    cout << result;
    if(result == expected){
        cout << " \33[32m[OK]\33[39m\n";
    }else{
        cout << " != " << expected << " \33[31m[FAIL]\33[39m\n";
    }
    result = handleFile<12>("input.txt");
    cout << result;
    clipboard(to_string(result));
}