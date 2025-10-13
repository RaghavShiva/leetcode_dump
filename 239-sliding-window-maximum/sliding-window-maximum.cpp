class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int length = nums.size();
        deque<int> window;
        vector<int> ans;
        for(int i=0;i<length;i++){
            if(!window.empty() && window.front()==i-k){
                window.pop_front();
            }
            while(!window.empty() && nums[window.back()]<nums[i]){
                window.pop_back();
            }
            window.push_back(i);
            if(i>=k-1)
            ans.push_back(nums[window.front()]);
        }
        return ans;
        //tc:O(n)
        //sc:O(n)
        //3 4 5, k=1
    }
};

