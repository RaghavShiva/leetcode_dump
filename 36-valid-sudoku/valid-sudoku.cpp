class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            vector<int> v(9,0),vv(9,0);
            
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                if(v[board[i][j]-'1']){
                    return false;
                }
                v[board[i][j]-'1']++;
                }
                if(board[j][i]!='.'){
                if(vv[board[j][i]-'1']){
                    return false;
                }
                vv[board[j][i]-'1']++;
                }
            }
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                vector<int> v(9,0);
                for(int a=0;a<3;a++){
                    for(int b=0;b<3;b++){
                        if(board[i+a][j+b]!='.'){
                            if(v[board[i+a][j+b]-'1']){
                                return false;
                            }
                            v[board[i+a][j+b]-'1']++;
                        }
                    }
                }
            }
        }
        return true;
    }
};