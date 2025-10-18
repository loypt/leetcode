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

const string singleDigit[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
const string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
const string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
const string thousands[] = {"", "M", "MM", "MMM"};

class Solution {
public:
    string intToRoman(int num) {
        return thousands[num / 1000] + hundreds[num % 1000 / 100] + tens[num % 100 / 10] + singleDigit[num % 10];
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();
    
    // Main Start
    int num = 3;
    Solution solution;
    cout << solution.intToRoman(num);
    // Main End
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

