class Solution {
public:
    int sum(int n){
        int s = 0;
        while(n){
            s+=n%10;
            n=n/10;
        }
        return s;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v(n);
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            v[i]={sum(nums[i]),nums[i]};
            mp[nums[i]]=i;
        }
        sort(v.begin(),v.end());
        int ans = 0;
    
        for(int i=0;i<n;i++){
            if(nums[i]!=v[i].second){
                int ind = mp[v[i].second];
                swap(nums[ind],nums[i]);
                mp[nums[ind]] = ind;
                mp[nums[i]] = i;
                ans++;
            }
        }
        return ans;
    }
};