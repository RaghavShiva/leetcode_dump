class Solution {
public:
    int helper(vector<int>&v, int x){
        int n = v.size();
        int f = 0;
        for(int i=0;i<n;i++){
            if(v[i]==x){
                f++;
            }
        }
        if(f==x){
            return x;
        }
        return -1;
    }
    int findLucky(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int ans = -1;
        for(int i=0;i<n;i++){
            ans = max(ans,helper(arr,arr[i]));
        }
        return ans;
    }
};