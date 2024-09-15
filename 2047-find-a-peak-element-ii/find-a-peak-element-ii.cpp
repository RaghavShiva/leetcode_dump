class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int l = 0;
        int h = n-1;
        while(l<=h){
            int mid = (l + h) / 2;
            int mx = 0;
            for(int i = 1; i < m; i++){
                if(mat[i][mid]>mat[mx][mid]){
                    mx = i;
                }
            }
            if(((mid > 0 && mat[mx][mid-1] < mat[mx][mid]) || mid == 0) && ((mid < n-1 && mat[mx][mid+1] < mat[mx][mid]) || mid == n-1)){
                return {mx,mid};
            }
            if(mid > 0 && mat[mx][mid-1] > mat[mx][mid]){
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return {};
    }
};