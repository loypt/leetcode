class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        auto sent = " " + sentence, word = " " + searchWord;
        int word_cnt = 0, j = 0;
        for (auto i = 0; i < sent.size() && j < word.size(); ++i) {
            word_cnt += sent[i] == ' ';
            if (sent[i] == word[j])
                ++j;
            else
                j = sent[i] == word[0] ? 1 : 0;
        }
        return j == word.size() ? word_cnt : -1;
    }
};
