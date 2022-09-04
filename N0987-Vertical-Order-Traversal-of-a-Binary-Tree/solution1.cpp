/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	vector<vector<int>> verticalTraversal(TreeNode* root) {
		queue<pair<TreeNode*, pair<int,int>>> q;
		map<int, multiset<pair<int,int>>> m;
		vector<vector<int>> res;
		q.push({ root,{0,0} });
		int row = 0;
		while (!q.empty()) {
			int n = q.size();
			for (int i = 0; i < n; i++) {
				auto front = q.front();
				TreeNode* node = front.first;
				auto [col, row] = front.second;
				m[col].insert({ row+1,node->val });
				q.pop();
				if (node->left) {
					q.push({ node->left, {col - 1, row+1 } }); 
				}
				if (node->right) {
					q.push({ node->right, {col + 1, row+1 } });
				}
			}
		}
		vector<int> temp = {};
		for (auto kv : m) {
			temp.clear();
			for (auto val : kv.second) {
				temp.push_back(val.second);
			}
			res.push_back(temp);
		}
		return res;
	}
};
