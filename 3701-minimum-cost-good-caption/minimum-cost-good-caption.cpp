class Solution {
const int MAXI = 1000000;
public:
    string minCostGoodCaption(string s) {
        int n = s.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (26, vector<int>(4,MAXI)));
        for(char ch='a'; ch<='z';ch++) dp[n-1][ch-'a'][1]=abs(s[n-1] - ch);
        
        for(int i=n-2;i>=0;i--) {
            for(char curr='a';curr<='z';curr++) {
                int ops = abs(s[i] - curr);
                
                for(int f=1;f<=3;f++) {
                    if(f==1) {
                        for(char ch='a';ch<='z';ch++) {
                            dp[i][curr-'a'][f] = min(dp[i][curr-'a'][f], ops + dp[i+1][ch-'a'][3]);
                        }
                    }
                    else {
                        dp[i][curr-'a'][f] = ops + dp[i+1][curr-'a'][f-1];
                        if(f==3) {
                            dp[i][curr-'a'][f] = min(dp[i][curr-'a'][f], ops + dp[i+1][curr-'a'][f]);
                        }
                    }
                }
            }
        }
        
        int ans = MAXI;
        string res;
        int next;
        int k = 3;
        
        for(char ch = 'a' ; ch<='z';ch++) {
            if(dp[0][ch-'a'][3] < ans) {
                ans = dp[0][ch-'a'][3];
                res = ch;
                int ops = abs(ch - s[0]);
                next = ans - ops;
            }
        }
        
        if(ans >= MAXI) return "";
        
        for(int i=1;i<n;i++) {
            if(k==1) {
                int curr = 3;
                for(char ch='a';ch<='z';ch++) {
                    if(dp[i][ch-'a'][curr] == next) {
                        res += ch;
                        int ops = abs(ch - s[i]);
                        next = next - ops;
                        break;
                    }
                }
                k = curr;
            }
            else if(k==2) {
                char ch = res.back(); 
                res += ch;
                
                int ops = abs(ch - s[i]);
                
                --k;
                next -= ops;
            }
            else {
                char ch = res.back(); 
                res += ch;
                
                int ops = abs(ch - s[i]);
                
                if(dp[i][ch-'a'][k]==dp[i][ch-'a'][k-1]) {
                    int tops = ops + abs(s[i+1] - ch);
                    for(char c='a';c<ch;c++) {
                        if(dp[i+2][c-'a'][3]==next-tops) {
                            --k;
                            break;
                        }
                    }
                }
                else {
                    if(dp[i][ch-'a'][k-1]==next) --k;
                }
                
                next -= ops;
            }
        }
        
        return res;
    }
};