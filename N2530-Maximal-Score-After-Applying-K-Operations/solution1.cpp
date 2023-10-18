class Solution {
public:
    long long maxKelements(vector<int> &nums, int k) {
        priority_queue<int> pq(less<int>(), move(nums));
        long long ans = 0;
        while (k--) {
            int x = pq.top();
            pq.pop();
            ans += x;
            pq.push((x + 2) / 3);
        }
        return ans;
    }
};
