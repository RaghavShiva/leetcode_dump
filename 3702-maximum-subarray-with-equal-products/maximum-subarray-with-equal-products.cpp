class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int d=1;
        for(int i = 0; i < n; i++){
            int c = nums[i];
            int g = nums[i];
            int l = nums[i];
            for(int j = i+1; j < n;j++){
                g = __gcd(g,nums[j]);
               
                c = c*nums[j];
                if(c>400000){
                    break;
                }
                l = (l*nums[j])/(__gcd(l,nums[j]));
                // cout<<l<<' '<<g<<' ';
                if(c==(l*g)){
                    d=max(d,j-i+1);
                }
            }
        }
        return d;
    }
};