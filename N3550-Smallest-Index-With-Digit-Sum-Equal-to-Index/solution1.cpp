class Solution {
public:
    int smallestIndex(const std::vector<int>& nums) {
        auto getDigitSum = [](int num) {
            int sum = 0;

            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }

            return sum;
        };

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            if (getDigitSum(nums[i]) == i) {
                return i;
            }
        }

        return -1;
    }
};
