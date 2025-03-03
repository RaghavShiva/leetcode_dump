class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>ans(n);
        int l=0,r=0;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                l++;
            }
            else if(nums[i]==pivot){
                r++;
            }
        }
        int a=0, b = l,c=l+r;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                ans[a]=nums[i];
                a++;
            }
            else if(nums[i]==pivot){
                ans[b] = nums[i];
                b++;
            }
            else{
                ans[c] = nums[i];
                c++;
            }
        }
        return ans;
    }
};