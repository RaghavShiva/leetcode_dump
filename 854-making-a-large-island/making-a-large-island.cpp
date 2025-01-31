class DisjointSet {
public:
vector<int> rank, parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
     int n = grid.size();
     DisjointSet ds(n*n);
     for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j]==0)
            continue;
            int dx[]={0,0,1,-1};
            int dy[]={1,-1,0,0};
            for(int k = 0; k < 4; k++){
                int nx = dx[k]+i;
                int ny = dy[k]+j;
                if(nx>=0 && nx<n && ny>=0 && ny<n && (grid[nx][ny]==1)){
                    ds.unionBySize(i*n+j,nx*n+ny);
                }
            }
        }
     }
     int mx = 0;
     for(int i = 0; i < n; i++){ 
        for(int j = 0; j < n; j++){
            if(grid[i][j]==1)
            continue;
            set<int> s;
            int dx[]={0,0,1,-1};
            int dy[]={1,-1,0,0};
            for(int k = 0; k < 4; k++){
                int nx = dx[k]+i;
                int ny = dy[k]+j;
                if(nx>=0 && nx<n && ny>=0 && ny<n && (grid[nx][ny]==1)){
                    s.insert(ds.findUPar(nx*n+ny));
                }
            }
             int sizeTotal = 0;
                for (auto it : s) {
                    sizeTotal += ds.size[it];
                }
                mx = max(mx, sizeTotal + 1);
        }
     }  
     for (int i = 0; i < n * n; i++) {
            mx = max(mx, ds.size[ds.findUPar(i)]);
        }
        return mx;
    }
};