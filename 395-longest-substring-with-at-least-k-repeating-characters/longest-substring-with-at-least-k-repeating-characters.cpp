class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int ans = 0;
        int mxu = 0;
        vector<int>f(26,0);
        for(int i=0;i<n;i++){
            if(f[s[i]-'a']==0){
                mxu++;
            }
            f[s[i]-'a']++;
        }
        for(int i=1;i<=mxu;i++){
            vector<int>vis(26,0);
            int l=0,r=0,cnt=0,j=0,c=0;
            while(r<n){
                if(cnt<=i){
                    j = s[r]-'a';
                    if(vis[j]==0){
                        cnt++;
                    }
                    vis[j]++;
                    if(vis[j]==k){
                        c++;
                    }
                    r++;
                }
                else{
                    j = s[l]-'a';
                    if(vis[j]==k){
                        c--;
                    }
                    vis[j]--;
                    if(vis[j]==0){
                        cnt--;
                    }
                    l++;
                }

                if(cnt==i && cnt==c){
                    ans = max(ans, r-l);
                }
            }
        }
        
        return ans;
    }
};