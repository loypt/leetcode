//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/5/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <unordered_map>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long lnumerator = numerator;
        long ldenominator = denominator;
        if (lnumerator % ldenominator == 0){
            return to_string(lnumerator/ldenominator);
        }

        string res;
        if (lnumerator < 0 ^ ldenominator < 0){
            res.push_back('-');
        }

        // Integer
        lnumerator = abs(lnumerator);
        ldenominator = abs(ldenominator);
        long intPart = lnumerator / ldenominator;
        res += to_string(intPart);
        res.push_back('.');

        // fractional
        string fracPart;
        unordered_map<long, int> remainderIndexMap;
        long remainder = lnumerator % ldenominator;
        int index = 0;
        while (remainder != 0 && !remainderIndexMap.count(remainder)){
            remainderIndexMap[remainder] = index;
            remainder *= 10;
            fracPart += to_string(remainder/ldenominator);
            remainder %= ldenominator;
            index++;
        }

        // if have loop knot
        if (remainder != 0){
            int insertIndex = remainderIndexMap[remainder];
            fracPart = fracPart.substr(0, insertIndex) + '(' + fracPart.substr(insertIndex);
            fracPart.push_back(')');
        }
        res += fracPart;

        return res;
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    int numerator = 821;
    int denominator = 370;
    Solution solution;
    cout << solution.fractionToDecimal(numerator, denominator);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

