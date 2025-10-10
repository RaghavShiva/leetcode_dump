class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<pair<int,int>>s;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j]-nums[i]==k){
                    s.insert({nums[j],nums[i]});
                }
            }
        } 
        return s.size();
    }
};