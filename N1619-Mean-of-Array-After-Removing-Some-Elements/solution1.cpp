class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int partialSum = accumulate(arr.begin() + n / 20, arr.begin() + (19 * n / 20), 0);
        return partialSum / (n * 0.9);
    }
};
