class Solution {
public:
    using pii = pair<int, int>;
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int res = INT_MIN;
        priority_queue<pii, vector<pii>, greater<pii>> heap;
        for (auto &point : points) {
            int x = point[0], y = point[1];
            while (!heap.empty() && x - heap.top().second > k) {
                heap.pop();
            }
            if (!heap.empty()) {
                res = max(res, x + y - heap.top().first);
            }
            heap.emplace(x - y, x);
        }
        return res;
    }
};
