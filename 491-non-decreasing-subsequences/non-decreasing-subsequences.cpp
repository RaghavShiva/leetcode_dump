class Solution {
public:
    void solve(int i, int j, int n, vector<int>& nums, set<vector<int>> &s, vector<int> v){
        if(i==n){
            if(v.size()>1)
            s.insert(v);
            return;
        }
        solve(i+1,j,n,nums,s,v);
        if(j==-1 || nums[j]<=nums[i]){
            v.push_back(nums[i]);
            solve(i+1,i,n,nums,s,v);
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> s;
        int n = nums.size();
        vector<int>v;
        solve(0,-1,n,nums,s,v);
        vector<vector<int>> ans;
        for(auto it:s){
            ans.push_back(it);
        }
        return ans;
    }
};