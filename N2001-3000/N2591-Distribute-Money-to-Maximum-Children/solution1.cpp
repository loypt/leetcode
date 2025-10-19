class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children) {
            return -1;
        }
        money -= children;
        int cnt = min(money / 7, children);
        money -= cnt * 7;
        children -= cnt;
        if ((children == 0 && money > 0) || (children == 1 && money == 3)) {
            cnt--;
        }
        return cnt;
    }
};
