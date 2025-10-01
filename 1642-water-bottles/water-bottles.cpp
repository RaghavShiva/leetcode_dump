class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int emt=0;
        int ans=0;
        ans+=numBottles;
        emt = numBottles;
        numBottles = 0;
        while(emt>=numExchange){
            numBottles = emt/numExchange;
            emt = emt%numExchange;
            ans += numBottles;
            emt+=numBottles;
        }
        return ans;
    }
};