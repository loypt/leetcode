class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freq;
        for (const string& word: words) {
            ++freq[word];
        }
        int res = 0;
        bool mid = false;
        for (const auto& [word, cnt]: freq) {
            string rev = string(1, word[1]) + word[0];
            if (word == rev) {
                if (cnt % 2 == 1) {
                    mid = true;
                }
                res += 2 * (cnt / 2 * 2);
            }
            else if (word > rev) {
                res += 4 * min(freq[word], freq[rev]);
            }
        }
        if (mid) {
            res += 2;
        }
        return res;
    }
};
