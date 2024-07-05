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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minDist = -1, maxDist = -1;
        int first = -1, last = -1, pos = 0;
        ListNode* cur = head;
        while (cur->next->next) {
            int x = cur->val;
            int y = cur->next->val;
            int z = cur->next->next->val;
            if (y > max(x, z) || y < min(x, z)) {
                if (last != -1) {
                    minDist = (minDist == -1 ? pos - last : min(minDist, pos - last));
                    maxDist = max(maxDist, pos - first);
                }
                if (first == -1) {
                    first = pos;
                }
                last = pos;
            }
            cur = cur->next;
            ++pos;
        }
        return {minDist, maxDist};
    }
};
