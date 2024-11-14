class Solution {
public:
    bool helper(int x, vector<int>& quantities, int n){
        int s = quantities.size();
        int c = 0;
        for( int i = 0; i < s; i++){
            c += ceil(quantities[i]*1.0/x);
        }
        return c<=n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int mx = *max_element(quantities.begin(),quantities.end());
        int l = 1, h = mx;
        int ans = -1;
        int m = 0;
        
        while(l <= h){
            m = (l+h)/2;
            if(helper(m,quantities,n)){
                h = m - 1;
                ans = m;
            }
            else{
                l = m + 1;
            }
        }
        return ans;
    }
};