class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int>v(26,0);
        int n = s.size();
        if(n<k)
        return 0;
        for(int i = 0; i < n; i++){
            v[s[i]-'a']++;
        }
        int cnt = 0;
        for(int i = 0; i < 26; i++){
            if(v[i]%2){
                cnt++;
            }
        }
        return cnt<=k;
    }
};