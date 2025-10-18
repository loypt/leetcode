class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<long long>> f(n+1, vector<long long>(m+1, LLONG_MAX));
        vector<long long> sub(n+1, 0);
        for(int i = 0; i < n; i++){
            sub[i+1] = sub[i] +  nums[i];
        }
        f[0][0] = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= min(i, m); j++){
                for(int k = 0; k < i ; k++){
                    f[i][j] = min(f[i][j], max(f[k][j-1], sub[i]-sub[k]));
                }
            }
        }
        return (int)f[n][m];
    }
};
