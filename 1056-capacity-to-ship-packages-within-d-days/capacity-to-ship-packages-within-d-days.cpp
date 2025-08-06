class Solution {
public:
    bool helper(int m, vector<int> &w, int d, int n){
        int c=0;
        for(int i=0;i<n;i++){
            c+=w[i];
            if(c>m){
                d--;
                c=w[i];
            }
        }
        return d>0;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int l, h=1e8;
        l = *max_element(weights.begin(),weights.end());
        while(l<=h){
            int m = (l+h)/2;
            if(helper(m,weights,days,n)){
                h = m-1;
            }
            else{
                l = m+1;
            }
        }
        return l; 
    }
};