class Solution {
private:
    void update(vector<int>& bits, int x, int change) {
        for (int i = 0; i < 32; i++) {
            if ((x >> i) & 1) {
                bits[i] += change;
            }
        }
    }
    
    int bitsToNum(vector<int>& bits) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            if (bits[i]) {
                result |= 1 << i;
            }
        }
        return result;
    }
    
    bool isSpecial(vector<int>& nums, int k, int len) {
        int n = nums.size();
        vector<int> bits(32);
        for (int i = 0; i < n; i++) {
            update(bits, nums[i], 1);
            if (i >= len) {
                update(bits, nums[i - len], -1);
            }
            if (i >= len - 1 && bitsToNum(bits) >= k) {
                return true;
            }
        }
        return false;
    }
    
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), start = 1, end = n + 1, mid;
        while (start < end) {
            mid = (start + end) / 2;
            if (!isSpecial(nums, k, mid)) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start != n + 1 ? start : -1;
    }
};
