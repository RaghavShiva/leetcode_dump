class Solution {
public:
    bool canJump(vector<int>& nums) {
        int steps = nums[0];
        
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(steps == 0){
            return false;
        }
            steps = max(steps - 1, nums[i]);
           
        }
        return true;

    }
};