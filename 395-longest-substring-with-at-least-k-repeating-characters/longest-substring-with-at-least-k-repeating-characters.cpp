class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            unordered_map<int,int>f,m;
            for(int j=i;j<n;j++){
                f[s[j]-'a']++;
            }

            for(auto it:f){
                if(it.second<k){
                    m[it.first]=it.second;
                }
            }

            for(auto it:m){
                auto itt = f.find(it.first);
                f.erase(itt);
            }

            for(int j=n-1;j>=i;j--){
                if(m.size()==0){
                    ans = max(ans, j-i+1);
                }
                else{
                    if(f.find(s[j]-'a')!=f.end()){
                        f[s[j]-'a']--;
                        if(f[s[j]-'a']<k){
                            m[s[j]-'a'] = f[s[j]-'a'];
                            auto it = f.find(s[j]-'a');
                            f.erase(it);
                        }
                    }
                    else{
                        m[s[j]-'a']--;
                        if(m[s[j]-'a']==0){
                            auto it = m.find(s[j]-'a');
                            m.erase(it);
                        }
                    }
                }
            }
        }
        return ans;
    }
};