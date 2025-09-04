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
            for(int j=target;j>=0;j--){
                if(cur[j]) continue;
                if(j>=nums[i-1]){
                    cur[j] = cur[j-nums[i-1]];
                }
            }
        }
        return cur[target];
    }
};

// tc - O(n*sum)
// sc - O(sum) // 2 1-D arrays -> 1 1-D array