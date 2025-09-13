class Solution {
public:
    void counterHu(int l, int r,string&s,vector<int>&m,int f){
        int n=s.size();
        if(l<0||r>=n)return;
        int cnt=0;
        while(l>=0&&r<n&&s[l]==s[r]){
            cnt++;
            m[r]=2*cnt+f;
              --l;
            ++r;
        }
        
    }
 vector<int> fun(string& s){
        int n=s.size();
        vector<int>m(n,1);
        for(int i=n-2;i>=0;i--){
               counterHu(i,i+1,s,m,0);
               counterHu(i-1,i+1,s,m,1);
        }
        return m;
    }
   

    int longestPalindrome(string s, string t) {
        
        int n1=s.size();
        int n2=t.size();
        vector<int>m1,m2;
        reverse(s.begin(),s.end());
        m1=fun(s);
        reverse(s.begin(),s.end());
         reverse(m1.begin(),m1.end());
        m2=fun(t);
        int dp[n1][n2];
        for(int i=n1-1;i>=0;i--){
            for(int j=0;j<n2;j++){
                dp[i][j]=0;
                     int prev=0;
                     if(i+1<n1&&j-1>=0)
                     prev=dp[i+1][j-1];
                     if(s[i]==t[j])
                     dp[i][j]=prev+1;
            }
        }
        int ans=0;
        
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                int val=dp[i][j];
                int v1=0,v2=0;
                if(i+val<n1)v1=m1[i+val];
                if(j-val>=0)v2=m2[j-val];
                ans=max(ans,max(v1,v2)+2*dp[i][j]);
            }
        }
        return ans;

    }
};