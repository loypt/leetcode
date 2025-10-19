class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        vector<int> s(n + 1);
        stack<int> stk;
        stk.push(0);
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + (hours[i - 1] > 8 ? 1 : -1);
            if (s[stk.top()] > s[i]) {
                stk.push(i);
            }
        }

        int res = 0;
        for (int r = n; r >= 1; r--) {
            while (stk.size() && s[stk.top()] < s[r]) {
                res = max(res, r - stk.top());
                stk.pop();
            }
        }
        return res;
    }
};
