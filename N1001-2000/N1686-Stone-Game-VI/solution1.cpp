class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<tuple<int, int, int>> values;
        for (int i = 0; i < aliceValues.size(); i++) {
            values.emplace_back(aliceValues[i] + bobValues[i], aliceValues[i], bobValues[i]);
        }
        sort(values.begin(), values.end(), [](tuple<int, int, int> &a, tuple<int, int, int> &b) {
            return get<0>(a) > get<0>(b);
        });
        int aliceSum = 0, bobSum = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                aliceSum += get<1>(values[i]);
            } else {
                bobSum += get<2>(values[i]);
            }
        }

        if (aliceSum > bobSum) {
            return 1;
        } else if (aliceSum == bobSum) {
            return 0;
        } else {
            return -1;
        }
    }
};
