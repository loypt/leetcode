//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/6/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;


class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int len = s.size(), ans = 0;
        for (int i =0, j = len-1; i < j; ++i) {
            for (int k = j; i!=k; k--) {
                if (s[i]==s[k]){
                    // need swap
                    for (; k < j; ++k) {
                        swap(s[k], s[k+1]);
                        ans++;
                    }
                    j--;
                    goto swapped;
                }
            }
            ans += len/2-i;
            swapped: continue;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    string s = "letelt";
    Solution solution;
    cout<< solution.minMovesToMakePalindrome(s);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


