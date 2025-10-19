class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int len = code.size();
        vector<int> res(len);
        if (k == 0) {
            return res;
        }
        code.resize(len * 2);
        copy(code.begin(), code.begin() + len, code.begin() + len);
        int l = k > 0 ? 1 : len + k;
        int r = k > 0 ? k : len - 1;
        int w = 0;
        for (int i = l; i <= r; i++) {
            w += code[i];
        }
        for (int i = 0; i < len; i++) {
            res[i] = w;
            w -= code[l];
            w += code[r + 1];
            l++;
            r++;
        }
        return res;
    }
};
