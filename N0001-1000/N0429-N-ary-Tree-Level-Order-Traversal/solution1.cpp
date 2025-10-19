/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr){
            return {};
        }
        vector<vector<int>> ans;
        queue<Node*> que;
        que.push(root);
        while(!que.empty()){
            int cnt = que.size();
            vector<int> level;
            for(int i = 0; i < cnt; ++i){
                Node* cur = que.front();
                que.pop();
                level.push_back(cur->val);
                for(Node* child : cur->children){
                    que.push(child);
                }
            }
            ans.push_back(move(level));
        }
        return ans;

    }
};
