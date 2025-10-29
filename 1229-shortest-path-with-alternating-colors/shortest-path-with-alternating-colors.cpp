class Solution {
public:
    vector<int> solve(int n, vector<vector<int>>&g1, vector<vector<int>>&g2){
        vector<int>ans(n,401);
        map<pair<int,int>,int>m;
        queue<tuple<int,int,int>>q;
        q.push({0,0,1});
        q.push({0,0,2});
        m[{0,1}]=1;
        m[{0,2}]=1;
        ans[0]=0;
        while(!q.empty()){
            auto[d,nd,c] = q.front();
            q.pop();
            ans[nd] = min(ans[nd],d);
            if(c==1){
                for(auto it:g2[nd]){
                    if(!m[{it,2}]){
                        q.push({d+1,it,2});
                        m[{it,2}]=1;
                    }
                }
            }
            else{
                for(auto it:g1[nd]){
                    if(!m[{it,1}]){
                        q.push({d+1,it,1});
                        m[{it,1}]=1;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(ans[i]==401) ans[i]=-1;
        }
        return ans;
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        int m1 = redEdges.size();
        int m2 = blueEdges.size();
        vector<vector<int>> g1(n),g2(n);
        for(int i=0;i<m1;i++){
            g1[redEdges[i][0]].push_back(redEdges[i][1]);
        }
        for(int i=0;i<m2;i++){
            g2[blueEdges[i][0]].push_back(blueEdges[i][1]);
        }

        return solve(n,g1,g2);
    }
};