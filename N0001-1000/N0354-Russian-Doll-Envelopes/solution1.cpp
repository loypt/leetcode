class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& A) {
        vector<int> tails;
        sort(A.begin(), A.end(), [](auto const& l, auto const& r) {
            if (l[0] == r[0]) {
                return l[1] > r[1];
            }
            return l[0] < r[0];
        });
        
        for (int i = 0; i < A.size(); i++) {
            int height = A[i][1];
            auto it = lower_bound(tails.begin(), tails.end(), height);
            if (it == tails.end()) {
                tails.push_back(height);
            } else {
                *it = height;
            }
        }
        
        return tails.size();
    }
};
