class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>v;
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]%2;
        }
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                v.push_back(i);
            }
        }
        v.push_back(n-1);
        vector<bool> ans;
        for(int i = 0; i < queries.size(); i++){
            auto it = lower_bound(v.begin(),v.end(),queries[i][0])-v.begin();
            auto it2 = lower_bound(v.begin(),v.end(),queries[i][1])-v.begin();
            ans.push_back(it==it2);
        }
        return ans;
    }
};