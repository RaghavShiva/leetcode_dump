class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int t=colors[0],n=colors.size();
        for(int i=0;i<n-1;i++){
            colors[i]=colors[i]^colors[i+1];
        }
        colors[n-1]^=t;
        t=0;
        for(int i=0;i<k-1;i++){
            if(colors[i]==0)
            t++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(t==0)
            ans++;
            if(colors[i]==0)
            t--;
            if(colors[(i+k-1)%n]==0)
            t++;
        }
        
        return ans;
    }
};