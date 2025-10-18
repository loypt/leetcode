class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num: nums) {
            ++freq[num];
        }
        return all_of(freq.begin(), freq.end(), [](auto p) { return p.second % 2 == 0; });
    }
};
