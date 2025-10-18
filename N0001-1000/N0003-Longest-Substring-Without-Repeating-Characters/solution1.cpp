//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 1/24/22.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char> temp_list = {};
        int max;
        if (s.length() > 0) {
            max = 1;
            for (int i=0; i < s.length(); i++) {
                for (int j=i; j < s.length(); j++) {
                    if (hasRepeat(temp_list, s[j])) {
                        temp_list.clear();
                        break;
                    }else{
                        temp_list.push_back(s[j]);
                        if (j-i+1 > max) {
                            max = j-i+1;
                        }
                    }
                }
            }
        }else{
            max = 0;
        }
        return max;
    }
    
    bool hasRepeat(vector<char> c_list, char c){
        for (char temp:c_list) {
            if (temp == c) {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    string s = "abcabcbb";
    string s1 = " ";
    string s2 = "";
    Solution solution;
    cout << solution.lengthOfLongestSubstring(s);
    
    return 0;
}

