class Solution {
public:
    vector<int> sumPrefixScores(vector<string> &words) {
        struct Node {
            Node *son[26]{};
            int score = 0;
        };
        Node *root = new Node();
        for (auto &word : words) {
            auto cur = root;
            for (char c : word) {
                c -= 'a';
                if (cur->son[c] == nullptr) cur->son[c] = new Node();
                cur = cur->son[c];
                ++cur->score;
            }
        }

        int n = words.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            auto cur = root;
            for (char c : words[i]) {
                cur = cur->son[c - 'a'];
                ans[i] += cur->score;
            }
        }
        return ans;
    }
};
