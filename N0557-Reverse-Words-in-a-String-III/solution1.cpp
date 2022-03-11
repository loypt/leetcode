//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/11/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    string reverseWords(string s) {
        string ret;
        int length = s.size();
        int i = 0;
        while (i < length){
            int start = i;
            while (i < length && s[i] != ' '){
                i++;
            }
            for (int p = start; p < i; ++p) {
                ret.push_back(s[start+i-1-p]);
            }
            while (i < length && s[i] == ' '){
                i++;
                ret.push_back(' ');
            }
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    string s = "Let's take LeetCode contest";
    Solution solution;
    cout << solution.reverseWords(s);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}


