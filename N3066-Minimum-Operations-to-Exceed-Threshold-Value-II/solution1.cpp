class Solution {
public:
    int minOperations(vector<int> &nums, int k) {
        int res = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());
        while (pq.top() < k) {
            long long x = pq.top(); pq.pop();
            long long y = pq.top(); pq.pop();
            pq.push(x + x + y);
            res++;
        }
        return res;
    }
};
