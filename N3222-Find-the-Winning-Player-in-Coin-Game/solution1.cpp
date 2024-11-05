class Solution {
public:
    string losingPlayer(int x, int y) {
        int ops = min(x, y / 4);
        return ops % 2 == 1 ? "Alice" : "Bob";
    }
};
