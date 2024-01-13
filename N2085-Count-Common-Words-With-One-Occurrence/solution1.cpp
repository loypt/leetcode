class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> freq1, freq2;
        for (const string& w: words1) {
            ++freq1[w];
        }
        for (const string& w: words2) {
            ++freq2[w];
        }

        int res = 0;
        for (const auto& [w, cnt1] : freq1) {
            if (cnt1 == 1 && freq2[w] == 1) {
                ++res;
            }
        }
        return res;
    }
};
