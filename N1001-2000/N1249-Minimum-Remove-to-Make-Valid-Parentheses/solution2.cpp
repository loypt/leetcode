class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') stk.push(i+1);
            else if(s[i] == ')'){
                if(!stk.empty() && stk.top() > 0){
                    stk.pop();
                }else{
                    stk.push(-(i+1));
                }
            }
        }
        while(!stk.empty()){
            s.erase(abs(stk.top())-1, 1);
            stk.pop();
        }
        return s;
    }
};
