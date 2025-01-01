class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int c = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == val){
                nums[i] = 51;
                c++;
            }
        }
        sort(nums.begin(),nums.end());
        return n-c;
    }
};