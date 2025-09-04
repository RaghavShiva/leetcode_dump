class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        // sum is odd
        if(sum%2!=0){
            return false;
        }

        int target = sum/2;
        vector<bool> cur(target+1,false);
        cur[0]=true;

        for(int i=1;i<=n;i++){
            // cur[0]=true;
            for(int j=target;j>=0;j--){
                bool not_taken = cur[j];
                bool taken = false;
                if(j>=nums[i-1]){
                    taken = cur[j-nums[i-1]];
                }
                cur[j] = taken|not_taken;
            }
        }
        return cur[target];
    }
};

// tc - O(n*sum)
// sc - O(sum) // 2 1-D arrays -> 1 1-D array