class Solution {
public:
    static constexpr int INF = 0x3f3f3f3f;
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.size();
        vector<vector<int>> d(n + 1, vector<int>(numCarpets + 1, INF));
        for (int j = 0; j <= numCarpets; j++) {
            d[0][j] = 0;
        }
        for (int i = 1; i <= n; i++) {
            d[i][0] = d[i - 1][0] + (floor[i - 1] == '1');
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= numCarpets; j++) {
                d[i][j] = d[i - 1][j] + (floor[i - 1] == '1');
                d[i][j] = min(d[i][j], d[max(0, i - carpetLen)][j - 1]);
            }
        }

        return d[n][numCarpets];
    }
};
