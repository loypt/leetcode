class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int mask = 0;
        long long ans = 0;
        cnt[0] = 1;
        for (int x : nums) {
            mask ^= x;
            ans += cnt[mask]; 
            cnt[mask]++;
        }
        return ans;
    }
};
