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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        
        int total = 0;
        for (ListNode* cur = head->next; cur; cur = cur->next) {
            if (cur->val == 0) {
                ListNode* node = new ListNode(total);
                tail->next = node;
                tail = tail->next;
                total = 0;
            }
            else {
                total += cur->val;
            }
        }
        
        return dummy->next;
    }
};
