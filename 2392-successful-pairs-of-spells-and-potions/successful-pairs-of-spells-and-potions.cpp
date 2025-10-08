class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n = spells.size();
        int m = potions.size();
        vector<int> ans(n,0);

        for(int i=0;i<n;i++){
            long long k = ceil(1.0*success/spells[i]);
            int ind = lower_bound(potions.begin(),potions.end(),k)-potions.begin();
            ans[i] = max(m-ind,0);
        }
        return ans;
    }
};