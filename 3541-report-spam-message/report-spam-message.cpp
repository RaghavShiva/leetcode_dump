class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        map<string,int> m;
        for(string s:bannedWords){
            m[s]++;
        }
        int cnt=0;
        for(string s:message){
            if(m[s])
            cnt++;
        }
        return cnt>=2;
    }
};