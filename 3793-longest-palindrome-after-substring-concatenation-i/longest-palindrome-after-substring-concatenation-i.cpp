class Solution {
public:
    bool isPalin(string &s){
        int n = s.size();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-1-i]){
                return false;
            }
        }
        return true;
    }
    int longestPalindrome(string s, string t) {
        vector<string> v,vv;
        int n = s.size();
        int m = t.size();
        v.push_back("");
        vv.push_back("");
        for(int i=0;i<n;i++){
            string ss = "";
            for(int j=i;j<n;j++){
                ss += s[j];
                v.push_back(ss);
            }
        }
        for(int i=0;i<m;i++){
            string ss = "";
            for(int j=i;j<m;j++){
                ss += t[j];
                vv.push_back(ss);
            }
        }
        int ans = 0;
        n = v.size();
        m = vv.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                string ss = v[i]+vv[j];
                if(isPalin(ss)){
                    int t = ss.size();
                    ans = max(ans,t);
                }
            }
        }
        return ans;
    }
};