class Solution {
public:
    bool isFound(vector<int>&v,int i,int n,vector<int>&vis){
        if(i==2*n-1){
            return true;
        }
        if(v[i]>0){
            return isFound(v,i+1,n,vis);
        }
        for(int j=n;j>0;j--){
            if(vis[j])
            continue;
            v[i]=j;
            vis[j]=1;
            if(j==1){
                if(isFound(v,i+1,n,vis)){
                    return true;
                }
            }
            else if(j+i<2*n-1 && v[i+j]==0){
                v[i+j]=j;
                if(isFound(v,i+1,n,vis)){
                    return true;
                }
                v[i+j]=0;
            }
            vis[j]=0;
            v[i]=0;
        }
        return false;

    }
    vector<int> constructDistancedSequence(int n) {
        vector<int>v(2*n-1,0);
        vector<int>vis(n+1,0);
        isFound(v,0,n,vis);
        return v;
    }
};