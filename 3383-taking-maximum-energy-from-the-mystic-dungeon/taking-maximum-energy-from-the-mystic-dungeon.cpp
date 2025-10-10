class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int ans = -1e9;
        for(int i=n-1;i>=0;i--){
            if(i<n-k){
                energy[i] += energy[i+k];
            }
            ans = max(ans,energy[i]);
        }
        return ans;
    }
};