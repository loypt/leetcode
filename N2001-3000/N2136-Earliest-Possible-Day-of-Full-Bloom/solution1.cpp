class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<int> id(n);  
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](int i, int j) {
            return growTime[i] > growTime[j];
        });
        int prev = 0, ans = 0;
        for (int i: id) {
            ans = max(ans, prev + plantTime[i] + growTime[i]);
            prev += plantTime[i];
        }
        return ans;
    }
};
