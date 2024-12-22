class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n;i+=3){
            set<int>s;
            for(int j = i; j < n; j++){
                s.insert(nums[j]);
            }
            if(s.size()==(n-i)){
                return i/3;
            }
        }
        return ceil(n*1.0/3);
    }
};