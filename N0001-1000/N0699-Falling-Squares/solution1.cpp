class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size();
        vector<int> ret(n);
        map<int, int> heightMap;
        heightMap[0] = 0;
        for (int i = 0; i < n; i++) {
            int size = positions[i][1];
            int left = positions[i][0], right = positions[i][0] + positions[i][1] - 1;
            auto lp = heightMap.upper_bound(left), rp = heightMap.upper_bound(right);
            int rHeight = prev(rp)->second;

            int height = 0;
            for (auto p = prev(lp); p != rp; p++) {
                height = max(height, p->second + size);
            }

            heightMap.erase(lp, rp);

            heightMap[left] = height;
            if (rp == heightMap.end() || rp->first != right + 1) {
                heightMap[right + 1] = rHeight;
            }
            ret[i] = i > 0 ? max(ret[i - 1], height) : height;
        }
        return ret;
    }
};
