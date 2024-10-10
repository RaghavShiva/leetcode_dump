class Solution {
public:
    int cur_sum(vector<int>& cardPoints, int k, int sum){
        int l = 0;
        int cur = 0;
        for(int i = 0; i < cardPoints.size(); i++){
            cur += cardPoints[i];
            if(i < k){
                if(i == k - 1){
                    sum = min(sum, cur);
                }
                continue;
            }
            cur -= cardPoints[l];
            l++;
            sum = min(sum, cur);
        }
       
        return sum;
    }
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        int n = cardPoints.size();
        for(int x : cardPoints){
            sum += x;
        }
        k = n - k;
        int ans = sum - cur_sum(cardPoints, k, sum);
        return ans;
    }
};