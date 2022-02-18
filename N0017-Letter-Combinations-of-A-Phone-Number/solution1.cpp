//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 1/24/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combineAlpha;
        if (digits == "") {
            return combineAlpha;
        }
        unordered_map<char, string> digitAlphaMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string combines;
        backtrack(combineAlpha, digitAlphaMap, digits, 0, combines);
        return combineAlpha;
    }
    
    void backtrack(vector<string>& combineAlpha, const unordered_map<char, string>& digitAlphaMap, const string& digits, int index, string& combines){
        if (index == digits.length()) {
            combineAlpha.push_back(combines);
        } else {
            char digit = digits[index];
            const string& letters = digitAlphaMap.at(digit);
            for ( const char& letter: letters) {
                combines.push_back(letter);
                backtrack(combineAlpha, digitAlphaMap, digits, index + 1, combines);
                combines.pop_back();
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();
    
    // Main Start
    string digits = "23";
    Solution solution;
    
    //Output normal constant
    /*
     cout << solution.letterCombinations(digits);
     */
    
    // Output Vectors
    vector<string> combineAlpha = solution.letterCombinations(digits);
    for(string s: combineAlpha){
        cout << s << ", ";
    }
    // Main End
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}
