class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;

    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return ans;
    }
    
    void dfs(int cur, int n, int k){
        if(temp.size() + (n - cur + 1) < k){
            return;
        }
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }
        temp.push_back(cur);
        dfs(cur+1, n, k);
        temp.pop_back();
        dfs(cur+1, n, k);
    }
};
