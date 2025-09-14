class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        for (string word : wordlist) {
            words_perfect.insert(word);
            string wordlow;
            for (char c : word) {
                wordlow += tolower(c);
            }
            if (!words_cap.count(wordlow)) {
                words_cap[wordlow] = word;
            }
            string wordlowDV = devowel(wordlow);
            if (!words_vow.count(wordlowDV)) {
                words_vow[wordlowDV] = word;
            }
        }

        vector<string> ans;
        for (string query : queries) {
            ans.push_back(solve(query));
        }
        return ans;
    }

private:
    unordered_set<string> words_perfect;
    unordered_map<string, string> words_cap;
    unordered_map<string, string> words_vow;

    string devowel(string word) {
        string ans;
        for (char c : word) {
            ans += isVowel(c) ? '*' : c;
        }
        return ans;
    }

    bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    string solve(string query) {
        if (words_perfect.count(query)) {
            return query;
        }

        string queryL;
        for (char c : query) {
            queryL += tolower(c);
        }
        if (words_cap.count(queryL)) {
            return words_cap[queryL];
        }

        string queryLV = devowel(queryL);
        if (words_vow.count(queryLV)) {
            return words_vow[queryLV];
        }

        return "";
    }
};
