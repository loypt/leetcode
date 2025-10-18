class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        for(const auto& v : edges){
            adj[v[0]].emplace_back(v[1]);
            adj[v[1]].emplace_back(v[0]);
        }
        queue<int> que;
        que.emplace(0);
        visited[0] = true;
        int dist = 1;
        int ans = 0;
        while(!que.empty()){
            int qsz = que.size();
            for(int i = 0; i < qsz; ++i){
                int cur = que.front();
                que.pop();
                for(const auto& v : adj[cur]){
                    if(visited[v]){
                        continue;
                    }
                    que.emplace(v);
                    int time = patience[v]*((2*dist-1)/patience[v])+2*dist+1;
                    ans = max(time, ans);
                    visited[v] = true;
                }
            }
            dist++;
        }
        return ans;
        
    }
};
