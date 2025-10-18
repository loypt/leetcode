class Solution {
public:
    pair<int,int>p[4]={{-1,0},{0,-1},{0,1},{1,0}};

    void flooding(vector<vector<char>>& board,int i,int j){
        board[i][j]='.';
        for(int k=0;k<4;k++){
            int in=i+p[k].first;
            int jn=j+p[k].second;
            if(in>=0 && jn>=0 && in<board.size() && jn<board[0].size() && board[in][jn]=='X'){
                flooding(board,in,jn);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int count=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='X'){
                    count+=1;
                    flooding(board,i,j);
                }
            }
        }
        return count;
    }
};
