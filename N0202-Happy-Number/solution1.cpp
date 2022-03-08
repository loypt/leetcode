//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/7/22.
//

#include <iostream>
#include <chrono>
#include <unordered_map>

using namespace std;
using namespace std::chrono;


class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> repeatmap;
        int remain, sum;
        while(sum != 1){
            sum = 0;
            while(n){
                remain = n%10;
                sum += remain*remain;
                n /= 10;
            }
            if(repeatmap.find(sum) == repeatmap.end()){
                repeatmap[sum]++;
                n = sum;
            }else{
                return false;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    int n = 19;
    Solution solution;
    cout << solution.isHappy(n);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


