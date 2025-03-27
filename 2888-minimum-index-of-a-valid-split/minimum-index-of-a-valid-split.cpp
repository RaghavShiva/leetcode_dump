class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int d = -1,cnt = 0;
        for(int i = 0;i < n; i++){
            if(cnt==0){
                d=nums[i];
            }
            cnt += (d==nums[i])?1:-1;
        }
        cnt = 0;
        for(int i = 0;i < n; i++){
            if(d == nums[i]){
                cnt++;
            }
        }
        int c=0;
        for(int i = 0;i < n-1; i++){
            if(d == nums[i]){
                c++;
            }
            if(c > (i+1)/2 && (cnt-c)>(n-i-1)/2){
                return i;
            }
        }
        return -1;
    }
};