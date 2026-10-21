class Solution {
public:
    int minOperations(string s) {
        string sorunavile = s;
        int n = (int)sorunavile.size();
        string t = sorunavile;
        sort(t.begin(), t.end());
        if (sorunavile == t) return 0;
        if (n == 2) return -1;
        if (sorunavile[0] == t[0] || sorunavile[n - 1] == t[n - 1]) return 1;
        char mn = *min_element(sorunavile.begin(), sorunavile.begin() + n - 1);
        char mx = *max_element(sorunavile.begin() + 1, sorunavile.end());
        if (mn == t[0] || mx == t[n - 1]) return 2;
        return 3;
    }
};
