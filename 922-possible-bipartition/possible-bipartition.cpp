class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        int m = dislikes.size();
        vector<vector<int>> g(n+1);
        for(int i=0;i<m;i++){
            g[dislikes[i][0]].push_back(dislikes[i][1]);
        }
        vector<bool> vis(n+1,false);
        for(int j=1;j<=n;j++){
            unordered_set<int>s1,s2;
            if(vis[j]) continue;
            queue<int>q;
        q.push(j);
        s1.insert(j);
        vis[j]=true;
        int k=0;
        while(!q.empty()){
            k++;
            int s = q.size();
            for(int i=0;i<s;i++){
                int u = q.front();
                q.pop();
                for(auto it:g[u]){
                    if(k%2){
                        if(s1.find(it)!=s1.end()){
                            return false;
                        }
                        if(s2.find(it)==s2.end()){
                            q.push(it);
                            s2.insert(it);
                            vis[it]=true;
                        }
                    }
                    else{
                        if(s2.find(it)!=s2.end()){
                            return false;
                        }
                        if(s1.find(it)==s1.end()){
                            q.push(it);
                            s1.insert(it);
                            vis[it]=true;
                        }
                    }
                }
            }
        }
        }
        
        return true;
    }
};