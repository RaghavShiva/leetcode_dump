class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = 0;
        int n = target.size();
        int c = 0;
        for(int i=0;i<n;i++){
            if(c<target[i]){
                ans+=target[i]-c;
            }
            c = target[i];
        }
        return ans;
    }
};