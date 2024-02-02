class Solution {
private:
    static constexpr int mod = 1000000007;

public:
    vector<int> numsGame(vector<int>& nums) {

        int n = nums.size();
        if (n == 1) {
            return {0};
        }

        for (int i = 0; i < n; ++i) {
            nums[i] -= i;
        }

        priority_queue q0{less{}, vector{min(nums[0], nums[1])}};
        priority_queue q1{greater{}, vector{max(nums[0], nums[1])}};
        long long sum0 = q0.top(), sum1 = q1.top();
        vector<int> ans = {0, static_cast<int>(sum1 - sum0)};

        for (int i = 2; i < n; ++i) {
            if (nums[i] <= q0.top()) {
                q0.push(nums[i]);
                sum0 += nums[i];
            }
            else {
                q1.push(nums[i]);
                sum1 += nums[i];
            }
            if (q0.size() == q1.size() + 2) {
                int u = q0.top();
                q0.pop();
                sum0 -= u;
                q1.push(u);
                sum1 += u;
            }
            else if (q0.size() + 1 == q1.size()) {
                int u = q1.top();
                q1.pop();
                sum1 -= u;
                q0.push(u);
                sum0 += u;
            }
            long long delta = (i & 1) ? sum1 - sum0 : sum1 - sum0 + q0.top();
            ans.push_back(delta % mod);
        }

        return ans;
    }
};
