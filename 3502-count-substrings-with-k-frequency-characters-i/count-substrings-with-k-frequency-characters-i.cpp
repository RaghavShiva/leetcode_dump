class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int ans = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            bool f = false;
            vector<int> cnt(26,0);
            for(int j = i; j < n; j++){
                cnt[s[j]-'a']++;
                if(cnt[s[j]-'a']==k){
                    f = true;
                }
                if(f){
                    ans++;
                }
            }
        }
        return ans;
    }
};