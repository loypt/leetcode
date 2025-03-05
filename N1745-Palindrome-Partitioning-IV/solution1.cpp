class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n));
        for (int length = 1; length < n; length++) {
            for (int start = 0; start <= n - length; start++) {
                int end = start + length - 1;
                if (length == 1) {
                    isPalindrome[start][end] = true;
                } else if (length == 2) {
                    isPalindrome[start][end] = s[start] == s[end];
                } else {
                    isPalindrome[start][end] = s[start] == s[end] && isPalindrome[start + 1][end - 1];
                }
            }
        }
        for (int start = 1; start < n - 1; start++) {
            if (!isPalindrome[0][start - 1]) {
                continue;
            }
            for (int end = start; end < n - 1; end++) {
                if (isPalindrome[start][end] && isPalindrome[end + 1][n - 1]) {
                    return true;
                }
            }
        }
        return false;
    }
};
