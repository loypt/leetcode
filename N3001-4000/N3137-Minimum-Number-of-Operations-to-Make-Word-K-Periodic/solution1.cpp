class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n = word.size(), res = INT_MAX;
        unordered_map<string, int> count;
        for (int i = 0; i < n; i += k) {
            string &&part = word.substr(i, k);
            count[part]++;
            res = min(res, n / k - count[part]);
        }
        return res;
    }
};
