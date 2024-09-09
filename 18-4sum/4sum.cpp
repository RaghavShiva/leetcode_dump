class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n<4)
        return {};
        set<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                vector<int> t;
                t.push_back(nums[i]);
                t.push_back(nums[j]);
                long long tr = target-0ll-nums[i]-nums[j];
                int l=j+1,r=n-1;
                while(l<r){
                    if(nums[l]+nums[r] == tr){
                        t.push_back(nums[l]);
                        t.push_back(nums[r]);
                        ans.insert(t);
                        t.pop_back();
                        t.pop_back();
                        l++;
                    } else if(nums[l]+nums[r] < tr)
                     l++;
                     else
                     r--;
                }
            }
        }
        vector<vector<int>> res;
        for(auto x:ans){
            res.push_back(x);
        }
        return res;
    }
};