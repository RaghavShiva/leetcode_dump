class Solution {
public:
    bool helper(int m,vector<int>candies, long long k){
        long long cnt=0;
        for(int i=0;i<candies.size();i++){
            cnt+=candies[i]/m;
        }
        return cnt>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int r = *max_element(candies.begin(),candies.end());
        int l=1;
        int ans=0;
        while(l<=r){
            int m =(l+r)/2;
            if(helper(m,candies,k)){
                ans = m;
                l=m+1;
            }
            else{
                r= m-1;
            }
        }
        return ans;
    }
};