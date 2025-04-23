class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        map<char,int> mp;
        for(int i=0;i<m;i++){
            mp[t[i]]++;
        }
        int cnt = 0;
        int len=1e9;
        int si=-1;
        int l=0;
        for(int i=0;i<n;i++){
            if(mp[s[i]]>0){
                cnt++;
            }
            mp[s[i]]--;
            while(cnt==m){
                if(len>i-l+1){
                    len=i-l+1;
                    si=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0){
                    cnt--;
                }
                l++;
            }
        }
        if(si==-1)
        return "";
        string ans = s.substr(si,len);
        return ans;
    }
};