class Solution {
public:
    bool check(int n){
        vector<int> v(10,0);
        while(n){
            int d = n%10;
            v[d]++;
            n=n/10;
        }
        for(int i=0;i<10;i++){
            if(v[i]>0 && v[i]!=i){
                return false;
            }
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        while(n){
            n++;
            if(check(n)){
            return n;
            }
        }
        return 1;
    }
};