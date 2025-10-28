class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        while(i<n){
            if(pq.empty()){
                pq.push({nums[i],1});
                i++;
            }
            else{
                auto [cur,l] = pq.top();
                if(cur==nums[i]){
                    pq.push({nums[i],1});
                    i++;
                }
                else if(cur == nums[i]-1){
                    pq.pop();
                    pq.push({nums[i],l+1});
                    i++;
                }
                else{
                    if(l<3){
                        return false;
                    }
                    pq.pop();
                }
            }
        }
        while(!pq.empty()){
            int l = pq.top().second;
            if(l<3) return false;
            pq.pop();
        }
        return true;
    }
};