class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n = g.size();
        int m = s.size();
        int j=0,ans=0,i=0;
        while(i<n && j<m){
            if(s[j]>=g[i]){
                j++;
                ans++;
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};