class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int>m;
        vector<int>ans;
        for(auto x:nums)
            m[x]++;
        for(auto x:m){
            if(x.second>nums.size()/3)
            ans.push_back(x.first);
        }
        return ans;
    }
};