class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       int m = matrix.size();
       int n = matrix[0].size();
       int l = 0,r = n-1,t = 0,b = m-1;
       vector<int>ans;
        while(t<=b && l<=r){
            for(int i=l;i<=r;i++){
                ans.push_back(matrix[t][i]);
            }
            t++;
            for(int i=t;i<=b;i++){
                ans.push_back(matrix[i][r]);
            }
            r--;
            if(t<=b){
            for(int i=r;i>=l;i--){
                ans.push_back(matrix[b][i]);
            }
            b--;
            }
            if(l<=r){
                for(int i=b;i>=t;i--){
                    ans.push_back(matrix[i][l]);
                }
                l++;
            }
            
        }
        return ans;
    }
};