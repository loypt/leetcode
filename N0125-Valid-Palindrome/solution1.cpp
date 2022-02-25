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
#include <stack>
#include <unordered_map>
#include <math.h>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    bool isPalindrome(string s) {
        // remove non-alphanumeric characters and change uppercase to lowercase
        string newstr;
        for (char c : s) {
            if (isalnum(c)) {
                newstr += tolower(c);
            }
        }
        string newstr_rev(newstr.rbegin(), newstr.rend());
        if (newstr == newstr_rev) {
            return true;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();
    
    // Main Start
    string s = "A man, a plan, a canal: Panama";
    Solution solution;
    cout << solution.isPalindrome(s);
    // Main End
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

