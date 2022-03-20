class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> res(n);
        vector<vector<int>> G(n);
        for(vector<int>& p : paths){
            G[p[0]-1].push_back(p[1]-1);
            G[p[1]-1].push_back(p[0]-1);
        }
        for(int i  = 0; i < n; i++){
            int colors[5] = {};
            for(int j : G[i]){
                colors[res[j]] = 1;
            }
            for(int c = 4; c > 0; --c){
                if(!colors[c]){
                    res[i] = c;
                }
            }
        }
        return res;
    }
};
