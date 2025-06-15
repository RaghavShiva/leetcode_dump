class Solution {
public:
    int maxDiff(int num) {
        int n1=0,n2=0;
        int t = num;
        vector<int> v;
        while(t){
            v.push_back(t%10);
            t=t/10;
        }
        reverse(v.begin(),v.end());
        int n = v.size();
        int k=0;
        for(int i=0;i<n;i++){
            if(v[i]!=9){
                k=i;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(v[i]==v[k]){
                n1 = n1*10+9;
            }
            else{
                n1 = n1*10+v[i];
            }
        }
        if(v[0]!=1){
            for(int i=0;i<n;i++){
                if(v[i]==v[0]){
                    n2 = n2*10+1;
                }
                else{
                    n2=n2*10+v[i];
                }
            }
        }
        else{
            for(int i=0;i<n;i++){
                if(v[i]!=v[0] && v[i]!=0){
                    t = i;
                    break;
                }
            }
            if(t>0){
                for(int i=0;i<n;i++){
                    if(v[i]==v[t]){
                        n2 = n2*10;
                    }
                    else{
                        n2 = n2*10+v[i];
                    }
                }
            }
            else{
                n2=num;
            }
            
        }
        cout<<n1<<' '<<n2;
        return n1-n2;
    }
};