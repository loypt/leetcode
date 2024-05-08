class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        int ans = 0;
        int rest = capacity;
        for (int i = 0; i < n; ++i) {
            if (rest >= plants[i]) {
                ++ans;
                rest -= plants[i];
            }
            else {
                ans += i * 2 + 1;
                rest = capacity - plants[i];
            }
        }
        return ans;
    }
};
