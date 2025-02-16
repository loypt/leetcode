class Solution {
public:
    bool solve(vector<int>& ans, int n, int idx, unordered_set<int>& st) {
        if (idx >= ans.size()) {
            return true;
        }
        
        if (ans[idx] != -1) {
            return solve(ans, n, idx + 1, st);
        }

        for (int i = n; i >= 1; i--) {
            if (st.find(i) != st.end()) {
                if (i == 1) {
                    ans[idx] = 1;
                    st.erase(i);
                    if (solve(ans, n, idx + 1, st)) {
                        return true;
                    }
                    // Backtrack
                    st.insert(i);
                    ans[idx] = -1;
                } 
                else if (idx + i < ans.size() && ans[idx + i] == -1) {
                    ans[idx] = i;
                    ans[idx + i] = i;
                    st.erase(i);
                    if (solve(ans, n, idx + 1, st)) {
                        return true;
                    }
                    st.insert(i);
                    ans[idx] = -1;
                    ans[idx + i] = -1;
                }
            }
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int>ans((n-1)*2+1,-1);
        unordered_set<int>st;
        for(int i=1;i<=n;i++){
            st.insert(i);
        }
        solve(ans,n,0,st);
        return ans;
    }
};
