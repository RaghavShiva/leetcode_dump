class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        long long mn = 1e11;
        long long mx = -1e11;
        long long c=0;
        for(int i=0;i<n;i++){
            c+=differences[i];
            mn = min(mn,c);
            mx = max(mx,c);
        }
        cout<<mn<<' '<<mx;
        mn = lower-mn;
        mx = upper-mx;
        mx=min(mx,upper*1ll);
        mn=max(mn,lower*1ll);
        if(mx-mn+1<0)
        return 0;
        return mx-mn+1;
    }
};