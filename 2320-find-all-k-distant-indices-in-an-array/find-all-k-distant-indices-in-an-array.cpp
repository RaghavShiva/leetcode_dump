class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
       vector<int>ans;
       set<int>s;
       int n = nums.size();
       for(int i=0;i<n;i++){
        if(nums[i]==key){
            for(int j=max(0,i-k);j<i;j++){
                s.insert(j);
            }
            for(int j=i;j<=min(n-1,i+k);j++){
                s.insert(j);
            }
        }
       }
       for(auto it:s){
        ans.push_back(it);
       }
       return ans;
    }
};