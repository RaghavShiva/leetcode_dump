class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        v.push_back(0);
        int c=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                if(!c){
                    v.push_back(0);
                }
                c++;
            }
            else{
                v.push_back(c);
                c=0;
            }
        }
        if(c==n){
            return c-1;
        }
       
        v.push_back(c);
        v.push_back(0);
        n = v.size()-1;
        int ans=0;
        for(int i=1;i<n;i++){
            cout<<v[i]<<" "<<endl;
            if(v[i]==0){
                ans = max(ans, v[i-1]+v[i+1]);
            }
        }
        return ans;
    }
};