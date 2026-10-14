class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if ((long long)sum > 9LL * num) return "";
        int k = sum / 9, r = sum % 9;
        string ans;
        ans.reserve(num);
        ans.append(k, '9');
        if (r) ans.push_back(char('0' + r));
        ans.append(num - k - (r ? 1 : 0), '0');
        return ans;
    }
};
