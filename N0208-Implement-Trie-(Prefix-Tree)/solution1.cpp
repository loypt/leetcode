//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 1/24/22.
//

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Trie {
private:
    vector<Trie*> children;
    bool isEnd;

    Trie* searchPrefix(string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            if (node->children[ch-'a'] == nullptr) {
                return nullptr;
            }
            node = node->children[ch-'a'];
        }
        return node;
    }
public:
    Trie(): children(26), isEnd(false) {}

    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            if (node->children[ch-'a'] == nullptr) {
                node->children[ch-'a'] = new Trie();
            }
            node = node->children[ch-'a'];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Trie* node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;
    }

    bool startsWith(string prefix) {
        return this->searchPrefix(prefix) != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    Trie trie = *new Trie();
    trie.insert("apple");
    cout << "trie.search(\"apple\") " << trie.search("apple") << endl;
    cout << "trie.search(\"app\") " << trie.search("app") << endl;
    cout << "trie.startsWith(\"app\") " << trie.startsWith("app") << endl;
    trie.insert("app");
    cout << "trie.search(\"app\") " << trie.search("app") << endl;
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

