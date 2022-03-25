class Solution {
public:
    bool isStraight(vector<int>& nums) {
        unordered_set<int> repeat;
        int maxn = 0, minn = 14;
        for(const auto& num : nums){
            if(num == 0) continue;
            maxn = max(maxn, num);
            minn = min(minn, num);
            if(repeat.find(num) != repeat.end()) return false;
            repeat.insert(num);
        }
        return maxn-minn < 5;

    }
};
