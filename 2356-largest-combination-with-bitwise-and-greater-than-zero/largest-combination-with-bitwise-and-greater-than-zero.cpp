class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<int>ans(24,0);
        int n=candidates.size();
        for(int b=0;b<24;b++){
            for(int i=0;i<n;i++){
                if(candidates[i]&1){
                    ans[b]++;
                }
                candidates[i]/=2;
        }
        }
        return *max_element(ans.begin(),ans.end());
    }
};