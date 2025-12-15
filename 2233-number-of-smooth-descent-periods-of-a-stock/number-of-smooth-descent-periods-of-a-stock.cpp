class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        int n = prices.size();
        int c = 1;
        for(int i=1;i<n;i++){
            if(prices[i]==(prices[i-1]-1)){
                c++;
            }
            else{
                ans += 1ll*c*(c+1)/2;
                c=1;
            }
        }
        ans += 1ll*c*(c+1)/2;
        return ans;
    }
};

