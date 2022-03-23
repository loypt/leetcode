class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(dfs(board, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k){
        if(i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || board[i][j] != word[k]){
            return false;
        }
        if(k == word.size()- 1){
            return true;
        } 
        char temp = board[i][j];
        board[i][j] = '#';
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        for(int p = 0; p < 4; ++p){
            int ni = i + dx[p], nj = j + dy[p];
            if(dfs(board, word, ni, nj, k+1)){
                return true;
            }
        }
        board[i][j] = temp;
        return false;
    }
};
