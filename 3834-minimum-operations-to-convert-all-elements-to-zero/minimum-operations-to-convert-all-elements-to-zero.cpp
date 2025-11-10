class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();  
        map<int,vector<int>>m;
        for(int i=0;i<n;i++){
            m[nums[i]].push_back(i);
        }
        int ans = 0;
        set<int>s;

        for(auto v:m){
            auto it = v.second;
            if(s.empty()){   
                for(auto itt:it){
                    s.insert(itt);
                }
                if(v.first!=0){
                    ans=1;
                }
            }
            else{
                for(int i=0;i<it.size();i++){
                    if(i==0){
                        ans++;
                    }
                    else{
                        auto l = s.lower_bound(it[i-1]);
                        auto h = s.lower_bound(it[i]);
                        if(l!=h){
                            ans++;
                        }
                    }
                }
                for(int i=0;i<it.size();i++){
                    s.insert(it[i]);
                }
            }
        }
        return ans;
    }
};