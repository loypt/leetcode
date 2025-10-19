class Solution {
public:
    unordered_map<int, vector<int>> g;
    unordered_map<int, bool> visited;
	
    void createGraph(vector<vector<int>>& edges) {
      for (auto e: edges) {
        g[e[0]].push_back(e[1]);
		g[e[1]].push_back(e[0]);
      }
    }
  
    int dfs(int node, int myCost, vector<bool>& hasApple) {
	  if (visited[node]) {
		  return 0;
	  }
	  visited[node] = true;
	  
      int childrenCost = 0;
      for (auto x: g[node]) { 
        childrenCost += dfs(x, 2, hasApple);
      }

      if (childrenCost == 0 && hasApple[node] == false) {
        return 0;
      }
	  
      return (childrenCost + myCost);
    }
  
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
      createGraph(edges);
      return dfs(0, 0, hasApple);
    }
};
