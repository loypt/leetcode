class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size(), res = 0;
        vector<int> count(26);
        for (auto c : letters) {
            count[c - 'a']++;
        }
        for (int s = 1; s < (1 << n); s++) {
            vector<int> wordCount(26);
            for (int k = 0; k < n; k++) {
                if ((s & (1 << k)) == 0) {
                    continue;
                }
                for (auto c : words[k]) {
                    wordCount[c - 'a']++;
                }
            }
            bool ok = true; 
            int sum = 0;
            for (int i = 0; i < 26; i++) {
                sum += score[i] * wordCount[i];
                ok = ok && (wordCount[i] <= count[i]);
            }
            if (ok) {
                res = max(res, sum);
            }
        }
        return res;
    }
};
