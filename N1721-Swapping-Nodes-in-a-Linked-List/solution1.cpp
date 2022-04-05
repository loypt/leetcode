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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* rp = head;
        ListNode* preK = nullptr;
        ListNode* tailK = nullptr;
        for(int i = 0; i < k; i++){
            preK = head;
            head = head->next;
        }
        ListNode* tmp = preK;
        tailK = rp;
        while(tmp){
            tmp = tmp->next;
            if(!tmp){
                break;
            }
            tailK = tailK->next;
        }
        swap(pre->val, tailK->val);
        return rp;
    }
};K
