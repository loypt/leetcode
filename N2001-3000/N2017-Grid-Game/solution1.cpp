class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        long long firstSum = accumulate(grid[0].begin(),grid[0].end(),0LL);
        long long miniSum = LONG_LONG_MAX, secondSum = 0;
        for(int i=0;i<n;i++){
            firstSum -= grid[0][i];
            miniSum = min(miniSum, max(firstSum, secondSum));
            secondSum += grid[1][i];
        }
        return miniSum;
    }
};
