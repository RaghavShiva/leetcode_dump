class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = 1e9;
        vector<int> prev(n),cur(n);
        for(int j=0;j<n;j++){
            cur[j] = matrix[0][j];
        }
        
        for(int i=1;i<n;i++){
            prev = cur;
            for(int j=0;j<n;j++){
                int up=1e9,ldg=1e9,rdg=1e9;
                up = prev[j];
                if(j>0){
                    ldg = prev[j-1];
                }
                if(j<n-1){
                    rdg = prev[j+1];
                }
                cur[j] =  matrix[i][j]+min({up,ldg,rdg});
            }   
        }
        for(int j=0;j<n;j++){
            ans = min(ans, cur[j]);
        }
        return ans;
    }
};