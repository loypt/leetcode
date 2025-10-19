class UnionFind {
    int root[100001], Size[100001];
public:
    int components;
    UnionFind(int n): components(n+1){
        fill(Size, Size+n+1, 1);
        iota(root, root+n+1, 0);
    }
    
    int Find(int x) {
        if (x==root[x]) 
            return x;
        return root[x] = Find(root[x]);
    }

    bool Union(int x, int y) {
        x=Find(x), y=Find(y);
        
        if (x == y) return 0;
        
        if (Size[x] > Size[y]) {
            Size[x] +=Size[y];
            root[y] = x;
        } 
        else {
            Size[y] += Size[x];
            root[x] = y;
        }       
        components--;
        return 1;
    }     
};

class Solution {
public:
    bitset<100000> grid=0;
    int m, n, N;
    inline int  idx(int r, int c){
        return r*n+c;
    }
    void cross(int r, int c, UnionFind& G) {
        for (int i = r + 1; i < m; i++) {
            if (grid[idx(i, c)]) break;
            G.Union(idx(i, c), N);
        }
        for (int i = r - 1; i >= 0; i--) {
            if (grid[idx(i, c)]) break;
            G.Union(idx(i, c), N);
        }
        for (int j = c + 1; j < n; j++) {
            if (grid[idx(r, j)]) break;
            G.Union(idx(r, j), N);
        }
        for (int j = c - 1; j >= 0; j--) {
            if (grid[idx(r, j)]) break;
            G.Union(idx(r, j), N);
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        this->m = m, this->n = n;
        N=n*m;
        UnionFind G(N);

        for (auto& ij : walls){
            int r = ij[0], c = ij[1];
            grid[idx(r, c)] = 1;
            G.components--;
        }
        for (auto& ij : guards){
            int r = ij[0], c = ij[1];
            grid[idx(r, c)] = 1;
            G.components--;
        }
        for (auto& ij : guards) {
            int r = ij[0], c = ij[1];
            cross(r, c, G);
        }
        return G.components-1;
    }
};


