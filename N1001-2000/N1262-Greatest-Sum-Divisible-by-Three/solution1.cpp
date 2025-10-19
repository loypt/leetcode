class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> v[3];
        for (int num: nums) {
            v[num % 3].push_back(num);
        }
        sort(v[1].begin(), v[1].end(), greater<int>());
        sort(v[2].begin(), v[2].end(), greater<int>());
        int tot = accumulate(nums.begin(), nums.end(), 0);
        int remove = INT_MAX;

        if (tot % 3 == 0) {
            remove = 0;
        }
        else if (tot % 3 == 1) {
            if (v[1].size() >= 1) {
                remove = min(remove, v[1].end()[-1]);
            }
            if (v[2].size() >= 2) {
                remove = min(remove, v[2].end()[-2] + v[2].end()[-1]);
            }
        }
        else {
            if (v[1].size() >= 2) {
                remove = min(remove, v[1].end()[-2] + v[1].end()[-1]);
            }
            if (v[2].size() >= 1) {
                remove = min(remove, v[2].end()[-1]);
            }
        }

        return tot - remove;
    }
};
