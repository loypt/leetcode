/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res, stack;
        for (ListNode* node = head; node; node = node->next) {
            while (stack.size() && res[stack.back()] < node->val) {
                res[stack.back()] = node->val;
                stack.pop_back();
            }
            stack.push_back(res.size());
            res.push_back(node->val);
        }
        for (int i: stack) res[i] = 0;
        return res;
    }
};
