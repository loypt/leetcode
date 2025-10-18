class Solution {
    static constexpr int N = 23;
    static constexpr int M = 401;
    static constexpr int MOD = 1e9 + 7;
    int d[N][M];
    string num;
    int min_sum;
    int max_sum;

    int dfs(int i, int j, bool limit) {
        if (j > max_sum) {
            return 0;
        }
        if (i == -1) {
            return j >= min_sum;
        }
        if (!limit && d[i][j] != -1) {
            return d[i][j];
        }
        int res = 0;
        int up = limit ? num[i] - '0' : 9;
        for (int x = 0; x <= up; x++) {
            res = (res + dfs(i - 1, j + x, limit && x == up)) % MOD;
        }
        if (!limit) {
            d[i][j] = res;
        }
        return res;
    }

    int get(string num) {
        reverse(num.begin(), num.end());
        this->num = num;
        return dfs(num.size() - 1, 0, true);
    }

    string sub(string num) {
        int i = num.size() - 1;
        while (num[i] == '0') {
            i--;
        }
        num[i]--;
        i++;
        while (i < num.size()) {
            num[i] = '9';
            i++;
        }
        return num;
    }
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(d, -1, sizeof d);
        this->min_sum = min_sum;
        this->max_sum = max_sum;
        return (get(num2) - get(sub(num1)) + MOD) % MOD;
    }
};
