class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        string ans = "";
        char c = s[0];
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(c==s[i]){
                cnt++;
            }
            else{
                cnt=1;
                c=s[i];
            }
            if(cnt == 3){
                cnt--;
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};