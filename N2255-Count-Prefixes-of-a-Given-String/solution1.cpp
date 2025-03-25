class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int res = 0;
        auto isPrefix = [&](const string& word) -> bool {
            if (s.size() < word.size()) {
                return false;
            }
            for (int i = 0; i < word.size(); ++i) {
                if (word[i] != s[i]) {
                    return false;
                }
            }
            return true;
        };
        
        for (const string& word: words) {
            if (isPrefix(word)) {
                ++res;
            }
        }
        return res;
    }
};
