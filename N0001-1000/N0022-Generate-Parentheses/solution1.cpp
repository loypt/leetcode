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
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string cur;
        generate_all_str(cur, n * 2, result);
        return result;
    }
    
    bool isValid(string& str){
        int count = 0;
        for (char c:str) {
            if (c == '(') {
                count++;
            }else{
                count--;
            }
            if (count < 0) {
                return false;
            }
        }
        if (!count) {
            return true;
        }
        return false;
    }
    
    void generate_all_str(string& cur, int n, vector<string>& result) {
        if (n == cur.size()) {
            if (isValid(cur)) {
                result.push_back(cur);
            }
            return;
        }
        cur += '(';
        generate_all_str(cur, n, result);
        cur.pop_back();
        cur += ')';
        generate_all_str(cur, n, result);
        cur.pop_back();
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();
    
    // Main Start
    Solution solution;
    vector<string> all_case =  solution.generateParenthesis(3);
    for (string str: all_case) {
        cout << str << endl;
    }
    // Main End
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}
