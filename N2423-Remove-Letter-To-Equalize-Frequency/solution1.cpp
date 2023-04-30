class Solution {
public:
    bool equalFrequency(string word) {
        int charCount[26] = {0};
        for (char& c : word) {
            charCount[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (charCount[i] == 0) {
                continue;
            }
            charCount[i]--;
            unordered_set<int> frequency;
            for (int f : charCount) {
                if (f > 0) {
                    frequency.insert(f);
                }
            }
            if (frequency.size() == 1) {
                return true;
            }
            charCount[i]++;
        }
        return false;
    }
};
