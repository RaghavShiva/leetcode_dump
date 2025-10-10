class Solution {
public:
    int next(int i, int n, int v){
        return ((i+v)%n+n)%n;
    }
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        int slow=0, fast=0; 
        for(int i=0;i<n;i++){
            if(nums[i]==0) continue;
            slow = i;
            fast = next(i,n,nums[i]);
            while(nums[slow]*nums[fast] > 0  && nums[fast]*nums[next(fast,n,nums[fast])]>0){
                if(slow == fast){
                    if(slow == next(slow,n,nums[slow])) break;
                    return true;
                }
                slow = next(slow,n,nums[slow]);
                fast = next(fast,n,nums[fast]);
                fast = next(fast,n,nums[fast]);
            }
            
            int j=i, v = nums[j];
            while(nums[j]*v>0){
                int t = next(j,n,nums[j]);
                nums[j]=0;
                j=t;
            }
        }
        return false;
    }
};