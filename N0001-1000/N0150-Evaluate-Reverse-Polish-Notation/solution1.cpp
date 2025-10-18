//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 3/3/22.
//

#include <iostream>
#include <chrono>
#include <stack>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> mystack;
        for (int i = 0; i < tokens.size(); ++i) {
            string& token = tokens[i];
            if (!(token == "+" || token == "-" || token == "*" || token == "/")){
                mystack.push(atoi(token.c_str()));
            }else{
                int num2 = mystack.top();
                mystack.pop();
                int num1 = mystack.top();
                mystack.pop();
                switch (token[0]) {
                    case '+':
                        mystack.push(num1+num2);
                        break;
                    case '-':
                        mystack.push(num1-num2);
                        break;
                    case '*':
                        mystack.push(num1*num2);
                        break;
                    case '/':
                        mystack.push(num1/num2);
                        break;
                }
            }
        }
        return mystack.top();
    }
};


int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    vector<string> tokens = {"4","13","5","/","+"};
    Solution solution;
    cout << solution.evalRPN(tokens);
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

