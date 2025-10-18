class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int x = *min_element(baseCosts.begin(), baseCosts.end());
        if (x >= target) {
            return x;
        }
        vector<bool> can(target + 1, false);
        int res = 2 * target - x;
        for (auto& b : baseCosts) {
            if (b <= target) {
                can[b] = true;
            } else {
                res = min(res, b);
            }
        }
        for (auto& t : toppingCosts) {
            for (int count = 0; count < 2; ++count) {
                for (int i = target; i; --i) {
                    if (can[i] && i + t > target) {
                        res = min(res, i + t);
                    }
                    if (i - t > 0) {
                        can[i] = can[i] | can[i - t];
                    }
                }
            }
        }
        for (int i = 0; i <= res - target; ++i) {
            if (can[target - i]) {
                return target - i;
            }
        }
        return res;
    }
};
