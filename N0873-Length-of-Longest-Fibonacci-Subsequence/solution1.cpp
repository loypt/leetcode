class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int len = arr.size();
        unordered_map<int, int> indices;
        for(int i = 0;  i < len; ++i){
            indices[arr[i]] = i;
        }
        vector<vector<int>> dp(len, vector<int>(len));
        int ans = 0;
        for(int i = 0; i < len; ++i){
            for(int j = i-1; j >= 0 && arr[j]*2 > arr[i]; --j){
                int k = -1;
                if(indices.count(arr[i] - arr[j])){
                    k = indices[arr[i] - arr[j]];
                }
                if(k >= 0){
                    dp[j][i] = max(dp[k][j]+1, 3);
                }
                ans = max(dp[j][i], ans);
            }
        }
        return ans;
    }
};
