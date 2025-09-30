class DSU{
    public:
    vector<int>size,parent;
    DSU(int n)
    {
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i =0;i<n+1;i++)parent[i]=i;
    }
    int findultiparent(int u)
    {
        if(parent[u] == u)return u;
        return parent[u] = findultiparent(parent[u]);
    }
    void unionBysize(int u,int v)
    {
        int ulp_u = findultiparent(u);
        int ulp_v = findultiparent(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u]>size[ulp_v])
        {
            size[ulp_u]+=size[ulp_v];
            parent[ulp_v] = ulp_u;
        }
        else
        {
            size[ulp_v]+=size[ulp_u];
            parent[ulp_u] = ulp_v;
        }
    }
};
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        unordered_map<int,int>mpp;
        for(int i =0;i<n;i++)mpp[row[i]] = i/2;

        DSU ds(n/2);
        int swaps = 0;
        for(int i =0;i<n;i++)
        {
            if(row[i]%2==0)
            {
                int u = row[i],v = row[i]+1;
                if(ds.findultiparent(mpp[u])!=ds.findultiparent(mpp[v]))
                {
                    swaps++;
                    ds.unionBysize(mpp[u],mpp[v]);
                }
            }
            else
            {
                int u = row[i],v = row[i]-1;
                if(ds.findultiparent(mpp[u])!=ds.findultiparent(mpp[v]))
                {
                    swaps++;
                    ds.unionBysize(mpp[u],mpp[v]);
                }
            }
        }
        return swaps;

    }
};