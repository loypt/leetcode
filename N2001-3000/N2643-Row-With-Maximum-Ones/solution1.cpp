class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxOnes = 0, rowIndex = 0;
        for (int i = 0; i < mat.size(); i++) {
            int tot = accumulate(mat[i].begin(), mat[i].end(), 0);
            if (tot > maxOnes) {
                maxOnes = tot;
                rowIndex = i;
            }
        }
        return {rowIndex, maxOnes};
    }
};
