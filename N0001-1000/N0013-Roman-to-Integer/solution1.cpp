//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 1/24/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <unordered_map>
#include <math.h>

using namespace std;
using namespace std::chrono;

class Solution {
private:
    unordered_map<char, int> valueOfSymbol = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
public:
    int romanToInt(string s) {
        int temp, res=0;
        for (int i=0; i < s.length(); i++) {
            temp = valueOfSymbol[s[i]];
            if (temp >= valueOfSymbol[s[i+1]] && i <= s.length()-1) {
                res += temp;
            }else {
                res -= temp;
            }
        }
        return res;
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();
    
    // Main Start
    string romanNum = "MCMXCIV";
    Solution solution;
    cout << solution.romanToInt(romanNum);
    // Main End
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

