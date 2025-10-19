//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/7/22.
//

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Solution{
public:
    bool isHappy(int n){
        int slowPos = n, fastPos = n;
        do {
            slowPos = getBitSquareSum(slowPos);
            fastPos = getBitSquareSum(fastPos);
            fastPos = getBitSquareSum(fastPos);
        }while(slowPos != fastPos);

        return slowPos == 1;
    }

    static int getBitSquareSum(int num){
        int sum = 0;
        while(num){
            int remain = num % 10;
            sum += remain * remain;
            num /= 10;
        }
        return sum;
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


