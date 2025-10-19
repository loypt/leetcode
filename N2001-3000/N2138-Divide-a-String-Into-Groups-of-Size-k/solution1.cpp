class Solution {
public:
    vector<string> divideString(string &s, int k, char fill) {
        auto [q, r]=div(s.size(), k);
        vector<string> ans(q+(r>0)); 
        for (int i=0; i<q; i++){
            ans[i]=s.substr(i*k, k);
        }
        if (r>0){
            ans.back()=s.substr(q*k);
            ans.back()+=string(k-r, fill);
        }
        return ans;
    }
};
