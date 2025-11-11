class DSU{
    vector<int> rank,parent,size;
    public:
        DSU(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1,0);
            for(int i=0;i<=n;i++)parent[i]=i;
        }
    int findUpar(int node){
        if(node==parent[node])return node;
        return parent[node]=findUpar(parent[node]);
    }

    void unionByRank(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if(ulp_u==ulp_v)return;
        if(rank[ulp_u]<rank[ulp_v])parent[ulp_u]=ulp_v;
        else if(rank[ulp_v]<rank[ulp_u])parent[ulp_v]=ulp_u;
        else {
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:

    int manhattan(vector<int>& a, vector<int>& b){
        return abs(a[0]-b[0])+abs(a[1]-b[1]);
    }

    bool valid(vector<vector<int>>& points , int val){
        int n=points.size();
        DSU d(2*n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(manhattan(points[i],points[j])<val){
                    d.unionByRank(i,j+n);
                    d.unionByRank(i+n,j);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(d.findUpar(i)==d.findUpar(i+n))return false;
        }
        return true;
    }
    
    int maxPartitionFactor(vector<vector<int>>& points) {
        int n=points.size();
        if(n==2)return 0;
        int low=0,high=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                high=max(high,manhattan(points[i],points[j]));
            }
        }

        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(valid(points,mid)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};