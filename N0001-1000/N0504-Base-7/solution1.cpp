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
    string convertToBase7(int num) {
        if(num == 0){
            return "0";
        }
        string res;
        string negative = num < 0 ? "-" : "";
        num = abs(num);
        while(num){
            res += to_string(num%7);
            num = num/7;
        }
        reverse(res.begin(), res.end());
        return negative+res;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    int num = -7;
    Solution solution;
    cout<< solution.convertToBase7(num);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


