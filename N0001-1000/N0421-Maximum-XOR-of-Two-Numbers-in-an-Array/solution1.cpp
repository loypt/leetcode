class Solution {
private:
    static constexpr int HIGH_BIT = 30;

public:
    int findMaximumXOR(vector<int>& nums) {
        int x = 0;
        for (int k = HIGH_BIT; k >= 0; --k) {
            unordered_set<int> seen;
            for (int num: nums) {
                seen.insert(num >> k);
            }
            int x_next = x * 2 + 1;
            bool found = false;
            
            for (int num: nums) {
                if (seen.count(x_next ^ (num >> k))) {
                    found = true;
                    break;
                }
            }

            if (found) {
                x = x_next;
            }
            else {
                x = x_next - 1;
            }
        }
        return x;
    }
};
