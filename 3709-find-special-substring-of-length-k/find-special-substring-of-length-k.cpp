class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.size();
        for(int i = 0; i < n-k+1; i++){
            char c = s[i];
            bool f = true;
            for(int j = 0; j < k;j++){
                if(c!=s[i+j]){
                    f=false;
                    break;
                }
            }
            if(f){
                if((i==0 || s[i-1]!=s[i])&& (i+k==n || s[i]!=s[i+k])){
                    return true;
                }
            }
        }
        return false;
    }
};