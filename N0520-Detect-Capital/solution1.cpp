//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/1/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <numeric>
#include <map>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    bool detectCapitalUse(string word) {
        // two cases
        if (word.length() >= 2 && islower(word[0]) && isupper(word[1]))
            return false;
        for (int i = 2; i < word.length(); ++i) {
            if(islower(word[i]) ^ islower(word[1]))
                return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    string s = "USB";
    Solution solution;
    cout << solution.detectCapitalUse(s);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

