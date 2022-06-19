struct Trie {
    vector<int> words; // index of words
    vector<Trie *> children;
    Trie() {
        children = vector<Trie *>(26, nullptr);
    }
    // Thanks to @huahualeetcode for adding this in case of memory leak
    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (children[i]) {
                delete children[i];
            }
        }
    }
    
    void add(const string &word, size_t begin, int index) {
        words.push_back(index);
        if (begin < word.length()) {
            if (!children[word[begin] - 'a']) {
                children[word[begin] - 'a'] = new Trie();
            }
            children[word[begin] - 'a']->add(word, begin + 1, index);
        }
    }
    
    vector<int> find(const string &prefix, size_t begin) {
        if (begin == prefix.length()) {
            return words;
        } else {
            if (!children[prefix[begin] - 'a']) {
                return {};
            } else {
                return children[prefix[begin] - 'a']->find(prefix, begin + 1);
            }
        }
    }
};

class WordFilter {
public:
    WordFilter(vector<string> words) {
        forwardTrie = new Trie();
        backwardTrie = new Trie();
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            forwardTrie->add(word, 0, i);
            reverse(word.begin(), word.end());
            backwardTrie->add(word, 0, i);
        }
    }
    
    int f(string prefix, string suffix) {
        auto forwardMatch = forwardTrie->find(prefix, 0);
        reverse(suffix.begin(), suffix.end());
        auto backwardMatch = backwardTrie->find(suffix, 0);
        // search from the back
        auto fIter = forwardMatch.rbegin(), bIter = backwardMatch.rbegin();
        while (fIter != forwardMatch.rend() && bIter != backwardMatch.rend()) {
            if (*fIter == *bIter) {
                return *fIter;
            } else if (*fIter > *bIter) {
                fIter ++;
            } else {
                bIter ++;
            }
        }
        return -1;
    }
    
private:
    Trie *forwardTrie, *backwardTrie;
};
