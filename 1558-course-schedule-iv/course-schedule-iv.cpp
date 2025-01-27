class Solution {
public:
    void bfs(vector<vector<int>> &g, int i,vector<vector<bool>> &v){
        queue<int>q;
        q.push(i);
        while(!q.empty()){
            int n = q.front();
            q.pop();
            for(auto it:g[n]){
                if(!v[i][it]){
                q.push(it);
                v[i][it]=true;
                // v[n][it]=true;
                }
            }
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
     int n = prerequisites.size();
     vector<vector<bool>>v(numCourses, vector<bool>(numCourses,false));
     vector<vector<int>>g(numCourses);
     for(int i = 0; i < n; i++){
        g[prerequisites[i][0]].push_back(prerequisites[i][1]);
     }  

     for(int i = 0; i < numCourses; i++){
            bfs(g,i,v);
     }
     vector<bool> ans;
    for(auto query:queries){
        ans.push_back(v[query[0]][query[1]]);
    }
    return ans;
    }
};