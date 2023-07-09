class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 1 || n == k) return 0;
        vector<int> candidates;
        for (int i = 0; i < n-1; i++)
        {
            candidates.push_back(weights[i] + weights[i+1]);
        }
        sort(candidates.begin(), candidates.end());
        long long mins = 0, maxs = 0;
        for (int i = 0; i < k-1; i++)
        {
            mins += candidates[i];
            maxs += candidates[n-2-i];
        }
        return maxs - mins;
    }
};
