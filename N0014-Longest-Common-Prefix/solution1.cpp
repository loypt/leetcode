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
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            prefix = longestCommonPrefix(prefix, strs[i]);
            if(prefix.size() == 0) {
                break;
            }
        }
        return prefix;
    }
    
    string longestCommonPrefix(const string& str1, const string& str2){
        int length = min(str1.size(), str2.size());
        int index = 0;
        while (index < length && str1[index] == str2[index]) {
            index++;
        }
        return str1.substr(0, index);
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();
    
    // Main Start
    vector<string> strs = {"flower","flow","flight"};
    Solution solution;
    cout << solution.longestCommonPrefix(strs);
    // Main End
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}
