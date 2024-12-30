class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        int m = 0;
        string s = "";
        string ans = "";
        char c = 'a';
        if(numFriends == 1){
            return word;
        }
        for(int i = 0; i < n; i++){
            c = max(c, word[i]);
        }
        for(int i = 0; i < n; i++){
            if(c == word[i]){
                m = n - numFriends + 1;
                if((n-i)<=m){
                    s = word.substr(i);
                }
                else{
                    s = word.substr(i,m);
                }
                ans = max(ans, s);
            }
        }
        return ans;
    }
};