//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/10/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = s.size();
        if (len < 2){
            return len;
        }

        int left = 0, right = 0;
        int res = 0, maxCount = 0;
        vector<int> freq(26);
        while(right < len){
            freq[s[right] - 'A']++;
            maxCount = max(maxCount, freq[s[right]-'A']);
            right++;

            if (right-left > maxCount+k){
                freq[s[left]-'A']--;
                left++;
            }
            res = max(res, right-left);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    string s = "ABAB";
    int k =2 ;
    Solution solution;
    cout << solution.characterReplacement(s, k);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


