class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        set<int> s;
        unordered_map<int,int> m;
        vector<int> ans(n,1);
        for(int i=0;i<n;i++){
            if(rains[i]==0){
                s.insert(i);
            }
            else{
                if(m.find(rains[i])!=m.end()){
                    auto it = s.lower_bound(m[rains[i]]);
                    if(it==s.end()){
                        return {};
                    }
                    ans[*it] = rains[i];
                    s.erase(it);
                }
                ans[i] = -1;
                m[rains[i]]=i;
                
            }
        }
        return ans;
    }
};