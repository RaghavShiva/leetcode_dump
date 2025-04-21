class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        n=n/2;
        int sum = 0;
        vector<int>a,b;
        vector<vector<int>>v(n+1),vv(n+1);
        for(int i=0;i<n;i++){
            sum+=nums[i]+nums[i+n];
            a.push_back(nums[i]);
            b.push_back(nums[i+n]);
        }
        int ss=sum/2;
        for(int i=0;i<(1<<n);i++){
            int c=0,s1=0,s2=0;
            for(int j=0;j<n;j++)
                if(i&(1<<j)){
                    s1+=a[j];
                    s2+=b[j];
                    c++;
                }
                v[c].push_back(s1);
                vv[c].push_back(s2);
        }
        for(int i=0;i<=n;i++){
            sort(vv[i].begin(),vv[i].end());
        }
        int ans = INT_MAX;
        for(int i=0;i<=n;i++){
            int m =v[i].size();
            for(int j=0;j<m;j++){
                int t = vv[n-i].size();
                int l = lower_bound(vv[n-i].begin(),vv[n-i].end(),ss-v[i][j])-vv[n-i].begin();
                if(l!=t){
                    ans = min(ans,abs(sum-2*(vv[n-i][l]+v[i][j])));
                }
                if(l!=0){
                    ans = min(ans,abs(sum-2*(vv[n-i][l-1]+v[i][j])));
                }
            }
        }
        return ans;
    }
};