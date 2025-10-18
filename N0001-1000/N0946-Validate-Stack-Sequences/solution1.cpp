class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int> stk;
        int j = 0;
        for(const auto& value : pushed){
            stk.push(value);
            while(!stk.empty() && j < n && stk.top() == popped[j]){
                stk.pop();
                j++;
            }
        }
        return j == n;
    }
};
