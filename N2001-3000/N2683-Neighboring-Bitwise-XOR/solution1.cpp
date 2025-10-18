class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xorTmp = 0;
        for (int x : derived) {
            xorTmp ^= x;
        }
        return xorTmp == 0;
    }
};
