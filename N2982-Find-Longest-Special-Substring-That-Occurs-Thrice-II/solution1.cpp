class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        unordered_map<char, vector<int>> cnt;
        for (int i = 0, j = 0; i < s.size(); i = j) {
            while (j < s.size() && s[j] == s[i]) {
                j++;
            }
            cnt[s[i]].emplace_back(j - i);
        }
        
        int res = -1;
        for (auto &[_, vec] : cnt) {
            int lo = 1, hi = n - 2;
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                int count = 0;
                for (int x : vec) {
                    if (x >= mid) {
                        count += x - mid + 1;
                    }
                }
                if (count >= 3) {
                    res = max(res, mid);
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }
        return res;
    }
};
