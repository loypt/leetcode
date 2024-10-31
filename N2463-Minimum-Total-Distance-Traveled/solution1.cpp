#define ll long long int
#define sz(a) (int)a.size()

class Solution {
    int n, m;
    ll dp[101][101][101];
    ll solve(vector<int>& robot, vector<vector<int>>& factory, int i, int j, int lim) {
		if(j >= m) return ((i < n) ? 1e10 : 0);
		
		if(i >= n) return 0;
        ll &ans = dp[i][j][lim];
        if(ans != -1) return ans;
		
        ans = 1e18;
		
		if(lim > 0) ans = solve(robot, factory, i + 1, j, lim - 1) + abs(robot[i] - factory[j][0]);
		
		if(j + 1 < m) ans = min(ans, solve(robot, factory, i, j + 1, factory[j + 1][1]));
        return ans;
    }
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        n = sz(robot);
        m = sz(factory);
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        memset(dp, -1, sizeof dp);
		
        return solve(robot, factory, 0, 0, factory[0][1]);
    }
};
