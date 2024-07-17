class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int res = 0;
        vector<int> opened(n, 0);
        vector<vector<int>> d(n, vector<int>(n, 1000000));

        for (int mask = 0; mask < (1 << n); ++mask) {
            for (int i = 0; i < n; ++i) {
                opened[i] = mask & (1 << i);
            }
            fill(d.begin(), d.end(), vector<int>(n, 1000000));
            for (const auto& road : roads) {
                int i = road[0], j = road[1], r = road[2];
                if (opened[i] > 0 && opened[j] > 0) {
                    d[i][j] = d[j][i] = min(d[i][j], r);
                }
            }

            for (int k = 0; k < n; ++k) {
                if (opened[k] > 0) {
                    for (int i = 0; i < n; ++i) {
                        if (opened[i] > 0) {
                            for (int j = i + 1; j < n; ++j) {
                                if (opened[j] > 0) {
                                    d[i][j] = d[j][i] = min(d[i][j], d[i][k] + d[k][j]);
                                }
                            }
                        }
                    }
                }
            }

            int good = 1;
            for (int i = 0; i < n; ++i) {
                if (opened[i] > 0) {
                    for (int j = i + 1; j < n; ++j) {
                        if (opened[j] > 0 && d[i][j] > maxDistance) {
                            good = 0;
                            break;
                        }
                    }
                    if (!good) {
                        break;
                    }
                }
            }

            res += good;
        }
        return res;
    }
};
