//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/7/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> resStrList(n);
        for (int i = 1; i <= n; ++i) {
            string s;
            if (i % 3 == 0){
                s += "Fizz";
            }
            if (i % 5 == 0){
                s += "Buzz";
            }
            if (s.size() == 0){
                s += to_string(i);
            }
            resStrList[i-1] = (s);
        }
        return resStrList;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    int n = 15;
    Solution solution;
    vector<string> resArray = solution.fizzBuzz(n);
    for (const auto& str:resArray) {
        cout << str << endl;
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


