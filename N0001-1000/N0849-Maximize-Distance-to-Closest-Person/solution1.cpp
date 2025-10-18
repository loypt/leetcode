class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int res = 0;
        int l = 0;
        while (l < seats.size() && seats[l] == 0) {
            ++l;
        }
        res = max(res, l);
        while (l < seats.size()) {
            int r = l + 1;
            while (r < seats.size() && seats[r] == 0) {
                ++r;
            }
            if (r == seats.size()) {
                res = max(res, r - l - 1);
            } else {
                res = max(res, (r - l) / 2);
            }
            l = r;
        }
        return res;
    }
};
