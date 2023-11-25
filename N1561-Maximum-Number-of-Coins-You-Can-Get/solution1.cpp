class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int length = piles.size();
        int rounds = length / 3;
        int coins = 0;
        int index = length - 2;
        for (int i = 0; i < rounds; i++) {
            coins += piles[index];
            index -= 2;
        }
        return coins;
    }
};

