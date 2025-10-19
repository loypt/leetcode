//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 1/24/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }
        char s_char_array[s.size()+1];
        char t_char_array[t.size()+1];
        strcpy(s_char_array, s.c_str());
        strcpy(t_char_array, t.c_str());

        sort(s_char_array, s_char_array + sizeof s_char_array);
        sort(t_char_array, t_char_array + sizeof s_char_array);

        for (int i = 0; i <= s.size(); ++i) {
            if (s_char_array[i] == t_char_array[i]){
                continue;
            } else{
                return false;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    string s = "a";
    string t = "b";
    Solution solution;
    cout << solution.isAnagram(s, t);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

