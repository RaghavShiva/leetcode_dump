class Solution {
public:
    int nbits(long long x){
        int c=0;
        while(x){
            if(x&1)
            c++;
            x=x>>1;
        }
        return c;
    }
    int makeTheIntegerZero(int num1, int num2) {
        
            if(num2>=num1)
            return -1;
            int c=0;
            long long x = num1;
            while(c<=60){
                x = x-num2;
                if(x<=0)
                return -1;
                c++;
                if(c>=nbits(x) && x>=c)
                return c;
            }
            return -1;
       
    }
};