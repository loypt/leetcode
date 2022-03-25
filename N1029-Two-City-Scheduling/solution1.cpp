class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(begin(costs), end(costs), [](const vector<int> &o1, const vector<int> &o2){
            return (o1[0]-o1[1] < o2[0]-o2[1]);
        });

        int n = costs.size() / 2;
        int total = 0;

        for(int i = 0; i < n; ++i){
            total += costs[i][0] + costs[n+i][1];
        }
        return total;
    }
};
