class Solution {
public:
    int solve(int i, int n, int b){
        if(i==n){
            return 1;
        }

        int a=0;
        for(int k=1;k<=n;k++){
            if(b&(1<<(k-1))){
                continue;
            }
            if((i+1)%k==0 || k%(i+1)==0)
            a=a+solve(i+1,n,b|(1<<(k-1)));
        }
        return a;
    }
    int countArrangement(int n) {
        int b=0;
        return solve(0,n,b);
    }
};