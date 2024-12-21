class Solution {
public:
    int ans = 0;
    bool visited[30005];
    long long dfs(int node, vector<vector<int>>& graph,vector<int>& values,int k){

        visited[node] = true;
        long long total = 0;
        for(auto child : graph[node]){
            if(!visited[child]){
                total += dfs(child , graph , values,k);
            }
        }
        if((1ll*values[node]+total)%k==0){
            ans++;
            return 0;
        }
        else{
            return values[node]+total;
        }
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> graph(n,vector<int>());

        for(int i = 0 ; i < edges.size();i++){
            int a = edges[i][0],b = edges[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        dfs(0,graph,values,k);
        if(ans==0)return 1;
        return ans;

    }
};
