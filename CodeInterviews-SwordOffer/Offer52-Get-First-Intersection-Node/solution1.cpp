/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       unordered_set<ListNode*> visited;
        ListNode *temp = headA;
        while (temp != nullptr){
            visited.insert(temp);
            temp = temp->next;
        }
        temp = headB;
        while (temp != nullptr){
            if (visited.count(temp)){
                return temp;
            }
            temp = temp->next;
        }
        return nullptr; 
    }
};
