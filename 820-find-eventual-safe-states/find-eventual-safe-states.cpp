class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>rev(n);
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for(int j:graph[i]){
                rev[j].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int t = q.front();
             ans.push_back(t);
             q.pop();
            for(int it:rev[t]){
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};