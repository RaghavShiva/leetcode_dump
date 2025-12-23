class Solution {
public:
    bool helper(vector<string> t){
        int n = t.size();
        for(int i=0;i<n-1;i++){
            if(t[i]>t[i+1]) return false;
        }
        return true;
    }
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int ans = 0;
        int m = strs[0].size();
        vector<string> v(n,"");
        for(int i=0;i<m;i++){
            vector<string>t=v;
            for(int j=0;j<n;j++){
                t[j]+=strs[j][i];
            }
            if(helper(t)){
                v=t;
            }
            else{
                ans++;
            }
        }
        return ans;
    }
};