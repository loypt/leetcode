class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = getMaxPile(piles);
        while (low <= high) {
            int k = low + ((high - low) >> 1);
            if (canEatAllPile(piles, k, h)) {
                high = k - 1;
            } else {
                low = k + 1;
            }
        }
        
        return low;
    }

    bool canEatAllPile(vector<int>& piles,int k,  int h){
        int countHour = 0;
        for(int pile : piles){
            countHour += pile/k;
            if(pile % k != 0){
                countHour++;
            }
        }

        return countHour <= h;
    }

    int getMaxPile(vector<int>& piles){
        int maxPile = INT_MIN;
        for(int pile : piles){
            maxPile = max(maxPile, pile);
        }
        return maxPile;
    }
};
