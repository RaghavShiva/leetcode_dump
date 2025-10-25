class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int t = 0;
        for(int i=0;i<n;i++){
            if(i%7==0){
                t++;
            }
            ans += t+(i%7);
        }
        return ans;
    }
};