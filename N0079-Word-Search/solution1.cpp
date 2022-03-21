class Solution {
public:
    vector<pair<int , int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                bool flag = check(board, visited, i, j, word, 0);
                if(flag){
                    return true;
                }
            }
        }
        return false;
    }
    bool check(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, string s, int k){
        if(board[i][j] != s[k]){
            return false;
        }else if(k == s.size()-1){
            return true;
        }
        visited[i][j] = true;
        bool result = false;
        for(const auto& dir : directions){
            int newi = i + dir.first, newj = j + dir.second;
            if(newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()){
                if(!visited[newi][newj]){
                    bool flag = check(board, visited, newi, newj, s, k+1);
                    if(flag){
                        result = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;
        return result;
    }
};
