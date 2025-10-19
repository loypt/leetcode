class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int n = word.size();
        long long res = 0;
        for (int i = 0; i < n; i++) {
            set<char> occur;
            int consonants = 0;
            for (int j = i; j < n; j++) {
                if (vowels.count(word[j])) {
                    occur.insert(word[j]);
                } else {
                    consonants++;
                }
                if (occur.size() == vowels.size() && consonants == k) {
                    res++;
                }
            }
        }
        return res;
    }
};
