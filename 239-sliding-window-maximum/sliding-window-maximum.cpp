class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            while(!dq.empty() && dq.front()+k==i){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            if(dq.empty())
            dq.push_back(i);
            else if(nums[dq.front()]>=nums[i]){
                dq.push_back(i);
            }
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};