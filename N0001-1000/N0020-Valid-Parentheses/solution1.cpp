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
    bool isValid(string s) {
        int len = s.size();
        //if odd, then must false
        if (len % 2 == 1) {
            return false;
        }
        unordered_map<char, char> pairs = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        cout << "pairs.count(c) : " << pairs.count(')') << endl;
        stack<char> cstack;
        for (char c: s) {
            if (pairs.count(c)) {
                if (cstack.empty() || cstack.top() != pairs[c]) {
                    return false;
                }
                cstack.pop();
            }
            else {
                cstack.push(c);
            }
        }
        return cstack.empty();
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();
    
    // Main Start
    
    string input = "()[]{}";
    Solution solution;
    cout << solution.isValid(input);
    // Main End
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

