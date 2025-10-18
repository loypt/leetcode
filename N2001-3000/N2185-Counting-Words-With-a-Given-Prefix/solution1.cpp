//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 2/27/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (string s:words) {
            if(s.substr(0, pref.size()) == pref){
                count++;
            }
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<string> words = {"pay","attention","practice","attend"};
    string pref = "at";
    Solution solution;
    cout << solution.prefixCount(words, pref);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

