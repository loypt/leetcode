class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int n = (int)prices.size(), ret = 0, v, p = 0;
        priority_queue<int> profits;
        stack<pair<int, int> > vp_pairs;
        while (p < n) {
            for (v = p; v < n - 1 && prices[v] >= prices[v+1]; v++);
            for (p = v + 1; p < n && prices[p] >= prices[p-1]; p++);
            while (!vp_pairs.empty() && prices[v] < prices[vp_pairs.top().first]) {
                profits.push(prices[vp_pairs.top().second-1] - prices[vp_pairs.top().first]);
                vp_pairs.pop();
            }
            while (!vp_pairs.empty() && prices[p-1] >= prices[vp_pairs.top().second-1]) {
                profits.push(prices[vp_pairs.top().second-1] - prices[v]);
                v = vp_pairs.top().first;
                vp_pairs.pop();
            }
            vp_pairs.push(pair<int, int>(v, p));
        }
        while (!vp_pairs.empty()) {
            profits.push(prices[vp_pairs.top().second-1] - prices[vp_pairs.top().first]);
            vp_pairs.pop();
        }
        for (int i = 0; i < k && !profits.empty(); i++) {
            ret += profits.top();
            profits.pop();
        }
        return ret;
    }
};
