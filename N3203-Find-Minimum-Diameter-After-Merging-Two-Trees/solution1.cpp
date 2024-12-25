class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &dist, int curr){
        dist[node]=curr;
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,dist,curr+1);
            }
        }
    }
    int diameter(vector<int> adj[], int n){
        vector<int> vis(n,0),dist(n,0);
        dfs(0,adj,vis,dist,0);
        int maxi=0;
        int leafnode=0;
        for(int i=0; i<n; i++){
            if(dist[i]>maxi){
                maxi=dist[i];
                leafnode=i;
            }
        }
        vector<int> vis1(n,0),dist1(n,0);
        dfs(leafnode,adj,vis1,dist1,0);
        maxi=0;
        for(int i=0; i<n; i++){
            if(dist1[i]>maxi){
                maxi=dist1[i];
            }
        }
        return maxi;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1;
        int m=edges2.size()+1;
        vector<int> adj1[n],adj2[m];
        for(auto it:edges1){
            int u=it[0],v=it[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        for(auto it:edges2){
            int u=it[0],v=it[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        int dia1=diameter(adj1,n);
        int dia2=diameter(adj2,m);
        int chk1=0,chk2=0;
        if(dia1%2==0){
            chk1=dia1/2;
        }
        else{
            chk1=dia1/2+1;
        }
        if(dia2%2==0){
            chk2=dia2/2;
        }
        else{
            chk2=dia2/2+1;
        }
        int ans=chk1+chk2+1;
        return max({ans,dia1,dia2});
    }
};
