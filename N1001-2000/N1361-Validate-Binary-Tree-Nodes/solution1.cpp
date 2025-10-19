class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indeg(n);
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) {
                ++indeg[leftChild[i]];
            }
            if (rightChild[i] != -1) {
                ++indeg[rightChild[i]];
            }
        }

        int root = -1;
        for (int i = 0; i < n; ++i) {
            if (!indeg[i]) {
                root = i;
                break;
            }
        }
        if (root == -1) {
            return false;
        }

        unordered_set<int> seen;
        queue<int> q;
        seen.insert(root);
        q.push(root);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (leftChild[u] != -1) {
                if (seen.count(leftChild[u])) {
                    return false;
                }
                seen.insert(leftChild[u]);
                q.push(leftChild[u]);
            }
            if (rightChild[u] != -1) {
                if (seen.count(rightChild[u])) {
                    return false;
                }
                seen.insert(rightChild[u]);
                q.push(rightChild[u]);
            }
        }

        return seen.size() == n;
    }
};
