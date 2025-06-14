class Solution {
public:
    int minMaxDifference(int num) {
        vector<int> v;
        int t = num;
        do{
            v.push_back(t%10);
            t=t/10;
        }
        while(t);
        reverse(v.begin(),v.end());
        int n = v.size();
        int d = -1;
        int m = 0;
        for(int i=0;i<n;i++){
            if(v[i]!=9 && d<0){
                d = v[i];
            }
            if(v[i]==d){
                t = t*10+9;
            } 
            else{
                t = t*10+v[i];
            }
            if(v[i]==v[0]){
                m = m*10;
            }
            else{
                m = m*10+v[i];
            }
        }
        
        return t-m;

    }
};