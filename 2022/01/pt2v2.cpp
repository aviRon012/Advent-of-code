#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int sum = 0;
    string line;
    vector<int> sums{};
    while(getline(cin, line)){
        if(line.length()){
            sum += stoi(line);
        }else{
            sums.push_back(sum);
            sum = 0;
        }
    }
    sort(sums.begin(),sums.end(), greater<int>());
    cout << sums[0] + sums[1] + sums[2];
}