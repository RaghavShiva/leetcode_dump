class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 1e9, d = 1e9;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int t = target - nums[i];
            int l = 0, r = n-1;
            while(l<r){
                if(l==i){
                    l++;
                    continue;
                }
                if(r==i){
                    r--;
                    continue;
                }
                if(nums[l]+nums[r]<=t){
                    int dd = target-(nums[i]+nums[l]+nums[r]);
                    if(d>dd){
                        d = dd;
                        ans = nums[i]+nums[l]+nums[r];
                    }
                    l++;
                }
                else{
                    int dd = (nums[i]+nums[l]+nums[r]) - target;
                    if(d>dd){
                        ans = nums[i]+nums[l]+nums[r];
                        d=dd;
                    }
                    r--;
                }
            }
        }
        return ans;
    }
};