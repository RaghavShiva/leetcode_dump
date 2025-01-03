class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
       int n = nums.size();
       vector<long> v(n,0LL);
       v[0]=nums[0];
       for(int i = 1; i < n; i++){
        v[i]=nums[i]+v[i-1];
       } 
       
       int c = 0;
       for(int i = 0; i < n-1; i++){
        if(v[i]>=(v[n-1]-v[i])){
            c++;
        }
       }
       return c;
    }
};