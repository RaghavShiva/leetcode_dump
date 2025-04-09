class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        set<int> s;
        for(int i=0;i<n;i++){
            if(nums[i]<k){
                return -1;
            }
            else if(nums[i]>k)
            s.insert(nums[i]);
        }
        return s.size();
    }
};