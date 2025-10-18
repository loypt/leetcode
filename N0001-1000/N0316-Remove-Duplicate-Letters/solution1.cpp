class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> vis(26), num(26); // vis represent stack visited
        for(const auto& c : s){
            num[c - 'a']++;
        }
        string stk;
        for(const auto& c : s){
            if(!vis[c-'a']){
                while(!stk.empty() && stk.back() > c){
                    if(num[stk.back() - 'a'] > 0){
                        vis[stk.back() - 'a'] = 0;
                        stk.pop_back();
                    }else{
                        break;
                    }
                }
                vis[c-'a'] = 1;
                stk.push_back(c);
            }
            num[c-'a'] -= 1;
        }
        return stk;
    }
};
