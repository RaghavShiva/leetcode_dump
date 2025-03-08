class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int ans = n;
        for(int i=0;i<n-k+1;i++){
            int c = 0;
            for(int j = 0;j<k;j++){
                if(blocks[i+j]=='W'){
                    c++;
                }
            }
            ans = min(ans,c);
        }
        return ans;
    }
};