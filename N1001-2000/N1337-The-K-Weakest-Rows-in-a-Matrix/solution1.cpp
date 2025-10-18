class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<pair<int, int>> power;
        for(int i = 0; i < m; ++i){
            int l = 0, r = n - 1, pos = -1;
            while(l <= r){
                int mid = (l+r)/2;
                if(mat[i][mid] == 0){
                    r = mid-1;
                }else{
                    pos = mid;
                    l = mid+1;
                }
            }
            power.emplace_back(pos+1, i);
        }
        priority_queue q(greater<pair<int ,int>>(), move(power));
        vector<int> ans;
        for(int i = 0; i < k; ++i){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};
