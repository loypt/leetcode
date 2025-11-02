class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, int> isExist;
        for (int num : nums) {
            isExist[num] = 1;
        }
        ListNode sentry(0, head);
        ListNode* p = &sentry;
        while (p->next) {
            if (isExist[p->next->val]) {
                p->next = p->next->next;
            } else {
                p = p->next;
            }
        }
        return sentry.next;
    }
};
