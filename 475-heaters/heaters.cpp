class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int n = houses.size();
        int m = heaters.size();

        int j=0;
        int ans = 0;
        
        for(int i=0;i<n;i++){
            while(j<m-1 && abs(houses[i]-heaters[j])>=abs(houses[i]-heaters[j+1])){
                j++;
            }
            ans = max(ans, abs(houses[i]-heaters[j]));
        }
        return ans;
    }
};