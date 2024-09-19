class Solution {
public:
static bool customComparison(vector<int> &v1, vector<int> &v2) {
        if (v1[0] == v2[0])
            return v1[1] > v2[1];
        return v1[0] < v2[0];
    }
    int maxPathLength(vector<vector<int>>& ct, int k) {
        int n=ct.size();
        vector<vector<int>>v(n,vector<int>(3));
        for(int i=0;i<n;i++){
            v[i][0]=ct[i][0];
            v[i][1]=ct[i][1];
            v[i][2]=i;
        }
        sort(v.begin(),v.end(),customComparison);
        int pos;
        for(int i=0;i<n;i++){
            if(v[i][2]==k){
               pos=i;
            }
        }
        
        vector<int>tt;
        for(int i=0;i<pos;i++){
            if(v[i][1]<v[pos][1]&&v[i][0]<v[pos][0]){
                if(tt.size()==0){
                    tt.push_back(v[i][1]);
                }
                else if(v[i][1]>tt.back()){
                    tt.push_back(v[i][1]);
                 }
                 else{
                    int ind = lower_bound(tt.begin(), tt.end(), v[i][1]) - tt.begin();
            tt[ind] = v[i][1];
                 }
            }
        }
        int n1=tt.size();
        vector<int>t;
        for(int i=pos+1;i<n;i++){
            if(v[i][1]>v[pos][1]&&v[i][0]>v[pos][0]){
                if(t.size()==0){
                    t.push_back(v[i][1]);
                }
                else if(v[i][1]>t.back()){
                    t.push_back(v[i][1]);
                 }
                 else{
                    int ind = lower_bound(t.begin(), t.end(), v[i][1]) - t.begin();
            t[ind] = v[i][1];
                 }
            }
        }
        return n1+t.size()+1;

    }
};