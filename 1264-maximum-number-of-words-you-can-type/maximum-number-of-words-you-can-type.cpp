class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        text+=" ";
        int n = text.size();
        int m = brokenLetters.size();
        bool f = false;
        int ans=0;
        for(int i=0;i<n;i++){
            if(text[i]==' '){
                if(!f){
                    ans++;
                }
                f=false;
                continue;
            }
            for(int j=0;j<m;j++){
                if(text[i]==brokenLetters[j]){
                    f=true;
                    break;
                }
            }
        }
        return ans;
    }
};