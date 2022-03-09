//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/8/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
private:
    vector<bool> versionState;
public:
    Solution(int n, int bad){
        versionState = vector<bool>(n, false);
        for (int i = bad-1; i < n; ++i) {
            versionState[i] = true;
        }
    }

    int firstBadVersion(int n) {
        int left = 1, right = n;
        while(left < right){
            int mid = left+(right-left)/2;
            if (isBadVersion(mid)){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }

    bool isBadVersion(int version){
        return versionState[version-1];
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    int n = 5;
    int bad = 4;
    Solution solution(n, bad);
    cout <<  solution.firstBadVersion(n);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


