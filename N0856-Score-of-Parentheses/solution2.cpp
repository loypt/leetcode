class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stk;
        for(const auto& c : s){
            if(c == '(') stk.push(0);
            else{
                if(stk.top() == 0){
                    stk.pop();
                    stk.push(1);
                }else{
                    int t = 0;
                    while(!stk.empty() && stk.top() != 0){
                        t += stk.top();
                        stk.pop();
                    }
                    stk.pop();
                    stk.push(2*t);
                }
            }
        }
        int sum = 0;
        while(!stk.empty()){
            sum += stk.top();
            stk.pop();
        }
        return sum;
    }
};
