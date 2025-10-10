class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        if(m>n){
            return {};
        }

        vector<int> v(26,0);
        vector<int> ans;
        int j=0;
        for(int i=0;i<m;i++){
            v[p[i]-'a']++;
        }
        vector<int> f(26,0);
        for(int i=0;i<n;i++){
            if(i<m-1){
                f[s[i]-'a']++;
            }
            else{
                bool fl = true;
                f[s[i]-'a']++;
                for(int j=0;j<26;j++){
                    if(v[j]!=f[j]){
                        fl=false;
                        break;
                    }
                }
                if(fl){
                    ans.push_back(i-m+1);
                }
                
                f[s[i-m+1]-'a']--;
                
            }
        }
        return ans;
    }
};