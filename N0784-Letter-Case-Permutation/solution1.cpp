class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        ans.push_back("");
        for(const auto& c : s){
            int n = ans.size();
            if(isalpha(c)){
                for(int i = 0; i < n; i++){
                    ans.push_back(ans[i]);
                    ans[i].push_back(toupper(c));
                    ans[n+i].push_back(tolower(c));
                }
            }else{
                for(int i = 0; i < n; i++){
                    ans[i].push_back(c);
                }
            }
        }
        return ans;
    }
};
