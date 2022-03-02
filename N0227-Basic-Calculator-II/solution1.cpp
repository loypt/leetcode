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

using namespace std;
using namespace std::chrono;

class Solution{
public:
    int calculate(string s){
        vector<int> mystack;
        char sign = '+';
        int num = 0;
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            if(isdigit(s[i])){
                num = num*10 + int(s[i]-'0');
            }
            if (!isdigit(s[i]) && s[i] != ' ' || i == len-1){
                switch (sign) {
                    case '+':
                        mystack.push_back(num);
                        break;
                    case '-':
                        mystack.push_back(-num);
                        break;
                    case '*':
                        mystack.back() *= num;
                        break;
                    default:
                        mystack.back() /= num;
                }
                sign = s[i];
                num = 0;
            }
        }
        return accumulate(mystack.begin(), mystack.end(), 0);
    }
};

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    string s = "31+2*2";
    Solution solution;
    cout << solution.calculate(s);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

