class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int c = 0;
        while(num2){
            if(num2&1){
                c++;
            }
            num2 = num2/2;
        }
        int x = 0;
        vector<int>v(31,0),vv(31,0);
        int j = 0;
        while(num1){
            if(num1&1){
                v[j]=1;
            }
            num1=num1/2;
            j++;
        }
        reverse(v.begin(),v.end());
        for(int i = 0; i < 31; i++){
             if(c<=0){
                break;
            }
            if(v[i]==1){
                c--;
                vv[i] = 1;
            }
             if(c<=0){
                break;
            }
        }
        reverse(vv.begin(),vv.end());
        for(int i = 0; i < 31; i++){
             if(c<=0){
                break;
            }
            if(vv[i]==0){
                vv[i]=1;
                c--;
            }
             if(c<=0){
                break;
            }
        }
        j=0;
        for(int i = 0; i < 31; i++){
            j += vv[i]*pow(2,i);
        }
        return j;
    }
};