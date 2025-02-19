class Solution {
public:
    void solve(vector<int>& jobs, int k, vector<int>&v,int n,int i,int &ans){
        if(i==n){
            ans = min(ans,*max_element(v.begin(),v.end()));
            return;
        }
        for(int j=0;j<k;j++){
            v[j]+=jobs[i];
            solve(jobs,k,v,n,i+1,ans);
            v[j]-=jobs[i];
            if(v[j]==0) break;
        }
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        vector<int> v(k,0);
        int n = jobs.size();
        int ans = 1e9;
         solve(jobs,k,v,n,0,ans);
         return ans;
    }
};