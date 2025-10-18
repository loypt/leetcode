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


class Automaton {
    string state = "start";
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };
    
    int get_col(char c) {
        if (isspace(c)) {
            return 0;
        }
        if (c == '+' or c == '-') {
            return 1;
        }
        if(isdigit(c)) {
            return 2;
        }
        return 3;
    }
public:
    int sign = 1;
    long long ans = 0;
    
    void get(char c) {
        state = table[state][get_col(c)];
        if (state == "in_number") {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }else if (state == "signed")
            sign =  c == '+' ? 1 : -1;
    }
};

class Solution {
public:
    int myAtoi(string s) {
        Automaton automaton;
        for (char c : s) {
            automaton.get(c);
        }
        return automaton.sign * automaton.ans;
    }
};
int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();
    
    // Main Start
    string str = "4193 with words";
    Solution solution;
    cout << solution.myAtoi(str);
    // Main End
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}
