class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos,
                                          vector<vector<int>>& friends, int id,
                                          int level) {
        int n = friends.size();
        vector<string> ans;
        int cur_lev = 0;
        queue<int> q;
        vector<bool> vis(n, false);
        q.push(id);
        vis[id] = true;
        while (!q.empty()) {
            int s = q.size();
            cur_lev++;
            for (int i = 0; i < s; i++) {
                int p = q.front();
                q.pop();
                for (auto it : friends[p]) {
                    if (!vis[it]) {
                        q.push(it);
                        vis[it] = true;
                    }
                }
            }

            if (cur_lev == level) {
                break;
            }
        }
        unordered_map<string,int>m;
        while(!q.empty()){
            int p = q.front();
            q.pop();
            for(string it:watchedVideos[p]){
                m[it]++;
            }
        }
        set<pair<int,string>>s;
        for(auto it:m){
            s.insert({it.second,it.first});
        }
        for(auto it:s){
            ans.push_back(it.second);
        }
        return ans;
    }
};