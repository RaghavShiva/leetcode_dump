class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        unordered_map<int,int>m;
        int n = nums.size();
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        for(int i=n-1;i>=0;i--){
            if(m[nums[i]]>0){
                int x = nums[i];
                int j=1;
                for(j=1;j*j<=x;j++){
                    if(x%j==0){
                        if(m[j]>0&&j!=x){
                            m[j]+=m[x];
                            m[x]=0;
                            break;
                        }
                    }
                }
                for(;j>1;j--){
                    if(x%j==0){
                        if(m[x/j]>0){
                            m[x/j]+=m[x];
                            m[x]=0;
                            break;
                        }
                    }
                }
            }
        }
        long long ans=0;
        for(auto it:m){
            ans+=1ll*it.second*it.first;
        }
        return ans;

    }
};