#include "../../aoc-utils.hpp"
#include <iostream>
#include <bitset>
using namespace std;
using namespace Aoc;

int expected = 198;

template<int n>
bool majorityAtIndex(vector<bitset<n>> &bits, int index)
{
    int count = 0;
    for(auto &b: bits) count += b[index];
    return count >= bits.size() - count;
}

template<int n>
bitset<n> majority(vector<bitset<n>> &bits)
{
    bitset<n> m;
    for(int i = 0; i < n; i++) m[i] = majorityAtIndex<n>(bits, i);
    return m;
}

template<int n>
int handleFile(const string &path)
{
    auto file = openFile(path);
    bitset<n> in, maj;
    vector<bitset<n>> bits;
    while(file >> in) bits.push_back(in);
    maj = majority<n>(bits);
    int gamma = maj.to_ulong();
    int epsilon = maj.flip().to_ulong();
    return gamma * epsilon;
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