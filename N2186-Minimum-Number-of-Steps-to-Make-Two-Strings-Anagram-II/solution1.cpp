//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 2/27/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <unordered_map>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int minSteps(string s, string t) {
        int count = 0;
        unordered_map<char, int> map;
        for(char c: s){
            map[c] += 1;
        }
        for(char c : t){
            map[c] -= 1;
        }
        for(auto& it: map){
            count += abs(it.second);
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    string s = "cotxazilut";
    string t = "nahrrmcchxwrieqqdwdpneitkxgnt";
    Solution solution;
    cout << solution.minSteps(s, t);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

