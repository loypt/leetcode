class Solution {
public:
    int maxmiumScore(vector<int>& cards, int cnt) {
        sort(cards.begin(), cards.end());
        
        int ans = 0;
        int tmp = 0;
        int odd, even = -1;
        int end = cards.size() - cnt;
        for (int i = cards.size() - 1; i >= end; i--) {
            tmp += cards[i];
            if (cards[i] & 1) {
                odd = cards[i];
            } else {
                even = cards[i];
            }
        }

        if (!(tmp & 1)) {
            return tmp;
        }

        for (int i = cards.size() - cnt - 1; i >= 0; i--) {
            if (cards[i] & 1) {
                if (even != -1) {
                    ans = max(ans, tmp - even + cards[i]);
                }
            } else {
                if (odd != -1) {
                    ans = max(ans, tmp - odd + cards[i]);
                }
            }
        }
        return ans;
    }
};
