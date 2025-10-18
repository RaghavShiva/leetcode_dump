class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int c = 0;
        int ans = 0 ;
        for(int i = 0; i < n; i++){
            if(i==0){
                c = nums[i]-k;
                nums[i]=c;
                c++; 
            }
            else if(c>=nums[i]-k && c<=nums[i]+k){
                nums[i] = c;
                c++;
            }
            else if(c<nums[i]-k){
                nums[i]=nums[i]-k;
                c=nums[i]+1;
            }
            else{
                nums[i]=c;
                ans++;
            }
        }
        return n - ans;
    }
};