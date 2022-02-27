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
#include <unordered_set>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int lpos = 0;
        int rpos = s.size()-1;
        while (lpos < rpos){
            s[lpos] ^= s[rpos];
            s[rpos] ^= s[lpos];
            s[lpos] ^= s[rpos];
            lpos++;
            rpos--;
        }
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<char> s = {'h','e','l','l','o'};
    Solution solution;
    solution.reverseString(s);
    for (char c : s) {
        cout << c;
    }
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

