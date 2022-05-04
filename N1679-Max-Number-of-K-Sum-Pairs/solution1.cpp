class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num: nums) {
            ++freq[num];
        }
        int ans = 0;
        for (auto [key, value]: freq) {
            if (key * 2 == k) {
                ans += value / 2;
            }
            else if (key * 2 < k && freq.count(k - key)) {
                ans += min(value, freq[k - key]);
            }
        }
        return ans;
    }
};
