class Solution {
public:
    void solve(vector<int> &c, int t, int i, int s,vector<vector<int>>&ans,vector<int>v){
        if(i<0){
            return;
        }
        if(s>t){
            return;
        }
        if(s==t){
            return ans.push_back(v);
        }
        s+=c[i];
        v.push_back(c[i]);
        solve(c,t,i,s,ans,v);
        v.pop_back();
        s-=c[i];
        solve(c,t,i-1,s,ans,v);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>>ans;
        vector<int>v;
        solve(candidates,target,n-1,0,ans,v);
        return ans;
    }
};