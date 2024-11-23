class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>>ans(n,vector<char>(m,'.'));
        for(int i =0; i<m; i++){
            int c=n-1;
            for(int j=n-1; j>=0;j--){
                if(box[i][j]=='#'){
                    ans[c][m-1-i]='#';
                    c--;
                }
                else if(box[i][j]=='*'){
                    ans[j][m-1-i]='*';
                    c=j-1;
                }
                
            }

        }
        return ans;
    }
};