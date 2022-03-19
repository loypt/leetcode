class Solution {
private:
    static constexpr int INF = 10000 * 101 + 1;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> f(k+2, vector<int>(n, INF));
        f[0][src] = 0;
        for(int t = 1; t<=k+1; t++){
            for(auto& flight : flights){
                int j = flight[0], i = flight[1], cost = flight[2];
                f[t][i] = min(f[t][i], f[t-1][j] + cost);
            }
        }
        int ans = INF;
        for(int t = 1; t <= k+1; t++){
            ans = min(f[t][dst], ans);
        }
        return (ans == INF ? -1 : ans);
    }
};
