class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        for (int i = 0; i < m; ++i) {
            int front_pos = n - 1;
            for (int j = n - 1; j >= 0; --j) {
                if (box[i][j] == '*') {
                    front_pos = j - 1;
                }
                else if (box[i][j] == '#') {
                    if (front_pos > j) {
                        box[i][front_pos] = '#';
                        box[i][j] = '.';
                        --front_pos;
                    }
                    else {
                        front_pos = j - 1;
                    }
                }
            }
        }

        vector<vector<char>> ans(n, vector<char>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[j][m - i - 1] = box[i][j];
            }
        }
        return ans;
    }
};
