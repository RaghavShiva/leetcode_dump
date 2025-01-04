class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int,int>>v(26,{0,0});
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(v[s[i]-'a'].first!=0){
                v[s[i]-'a'].second = i;
            }
            else{
                v[s[i]-'a'].first = i+1;
            }
        }
        int ans = 0;
        for(int i = 0; i < 26; i++){
            int l = v[i].first;
            int r = v[i].second;
            set<char>st;
            while(l<r){
                st.insert(s[l]);
                l++;
            } 
            ans += st.size();
            
        }
        return ans;
    }
};