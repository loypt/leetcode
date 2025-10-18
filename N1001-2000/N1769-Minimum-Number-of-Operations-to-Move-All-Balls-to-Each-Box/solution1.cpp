class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int sm = 0;
            for (int j = 0; j < n; j++) {
                if (boxes[j] == '1') {
                    sm += abs(j - i);
                }
            }
            res[i] = sm;
        }
        return res;
    }
};
