class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(), score.end(), [&](const vector<int>& u, const vector<int>& v) {
            return u[k] > v[k];
        });
        return score;
    }
};
