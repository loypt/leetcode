class Solution {
public:
    int lengthLongestPath(string input) {
        int n = input.size();
        int pos = 0;
        int ans = 0;
        stack<int> stk;

        while(pos < n){
            int depth = 1;
            while(pos < n && input[pos] == '\t'){
                pos++;
                depth++;
            }

            int len = 0;
            bool isFile = false;
            while(pos < n && input[pos] != '\n'){
                if(input[pos] == '.'){
                    isFile = true;
                }
                len++;
                pos++;
            }

            pos++;
            while(stk.size() >= depth){
                stk.pop();
            }
            if(!stk.empty()){
                len += stk.top() +1;
            }
            if(isFile){
                ans = max(ans, len);
            }else{
                stk.emplace(len);
            }
        }
        return ans;
    }
};
