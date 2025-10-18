class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operation = 0;
        for (int num : nums) {
            if (num == (operation % 2)) {
                operation++;
            }
        }
        return operation;
    }
};
