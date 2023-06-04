class Solution {
public:
    int maxRepOpt1(string text) {
        unordered_map<char, int> count;
        for (auto c : text) {
            count[c]++;
        }

        int res = 0;
        for (int i = 0; i < text.size(); ) {
            int j = i;
            while (j < text.size() && text[j] == text[i]) {
                j++;
            }
            int cur_cnt = j - i;

            if (cur_cnt < count[text[i]] && (j < text.size() || i > 0)) {
                res = max(res, cur_cnt + 1);
            }

            int k = j + 1;
            while (k < text.size() && text[k] == text[i]) {
                k++;
            }
            res = max(res, min(k - i, count[text[i]]));
            i = j;
        }
        return res;
    }
};
