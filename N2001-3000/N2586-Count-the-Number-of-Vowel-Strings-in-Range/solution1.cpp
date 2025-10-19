class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int ans = 0;
        for (int i = left; i <= right; ++i) {
            const string& word = words[i];
            if (vowels.count(word[0]) && vowels.count(word.back())) {
                ++ans;
            }
        }
        return ans;
    }
};
