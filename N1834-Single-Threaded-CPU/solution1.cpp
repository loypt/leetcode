class Solution {
private:
    using PII = pair<int, int>;
    using LL = long long;

public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return tasks[i][0] < tasks[j][0];
        });

        vector<int> ans;
        priority_queue<PII, vector<PII>, greater<PII>> q;
        LL timestamp = 0;
        int ptr = 0;
        
        for (int i = 0; i < n; ++i) {
            if (q.empty()) {
                timestamp = max(timestamp, (LL)tasks[indices[ptr]][0]);
            }
            while (ptr < n && tasks[indices[ptr]][0] <= timestamp) {
                q.emplace(tasks[indices[ptr]][1], indices[ptr]);
                ++ptr;
            }
            auto&& [process, index] = q.top();
            timestamp += process;
            ans.push_back(index);
            q.pop();
        }
        
        return ans;
    }
};
