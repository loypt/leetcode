class Solution {
public:
    vector<int> v;
    vector<vector<int>> rects_in;

    int area(vector<int>& r) {
        return (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
    }

    Solution(vector<vector<int>>& rects) {
        rects_in = rects;
        for (auto& r : rects_in) {
            v.push_back(area(r) + (v.empty() ? 0 : v.back()));
        }
    }

    vector<int> pick() {
        int rnd = rand() % v.back();
        auto it = upper_bound(v.begin(), v.end(), rnd);
        int idx = it - v.begin();

        // pick a random point in rect[idx]
        auto r = rects_in[idx];
        return {
                rand() % (r[2] - r[0] + 1) + r[0],
                rand() % (r[3] - r[1] + 1) + r[1]
        };
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
