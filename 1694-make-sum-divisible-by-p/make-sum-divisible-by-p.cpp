class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int s=0;

        for(int i=0;i<n;i++){
            s = (s+nums[i])%p;
        }

        if(s==0){
            return 0;
        }
        
        unordered_map<int,int>m;
        m[0]=-1;
        int cs=0;
        int ans=n;
        for(int i=0;i<n;i++){
            cs = (cs+nums[i])%p;
            int ns = (cs-s+p)%p;
            if(m.find(ns)!=m.end()){
                ans = min(ans,i-m[ns]);
            }
            m[cs] = i;
        }
        
        return ans==n?-1:ans;
    }
};