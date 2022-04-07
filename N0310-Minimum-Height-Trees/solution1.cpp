class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
            return {0};
        vector<int> degree(n);   //每个节点对应的度数
        map<int,vector<int>> m;  //邻接表
        vector<int> res; //结果
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            degree[u]++;
            degree[v]++;
            m[u].push_back(v);
            m[v].push_back(u);
        }
        queue<int> q;
        //把叶子节点入栈
        for(int i=0;i<n;i++)
            if(degree[i]==1)
                q.push(i);
        //从外向内一层一层剥，每次加入的都是一层的
        while(!q.empty()){
            res.clear();
            int sz=q.size();
            //一层全部加入结果并且清出去
            for(int i=0;i<sz;i++){
                int t=q.front();
                q.pop();
                res.push_back(t);
                //加入t的邻接叶子节点
                degree[t]--;
                for(auto j:m[t]){
                    degree[j]--;
                    if(degree[j]==1)
                        q.push(j);
                }    
            }
        }
        return res; 
    }
};
