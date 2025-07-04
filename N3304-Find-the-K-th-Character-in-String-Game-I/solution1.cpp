class Solution {
public:
    char kthCharacter(int k) {
        return 'a' + popcount((uint32_t) k - 1);
    }
};
