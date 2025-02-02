class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.size();
        int a=0,b=0,c=0,d=0;
        int ans=0;
        for(int i = 0; i < n; i++){
            if(s[i]=='N'){
                a++;
            }
            else if(s[i]=='S'){
                b++;
            }
            else if(s[i]=='E'){
                c++;
            }
            else {
                d++;
            }
            int aa=a,bb=b,cc=c,dd=d,kk=k;
            if(aa>bb){
                if(bb<=kk){
                    kk-=bb;
                    aa+=bb;
                    bb=0;
                }
                else{
                    bb-=kk;
                    aa+=kk;
                    kk=0;
                }
            }
            else{
               if(aa<=kk){
                    kk-=aa;
                    bb+=aa;
                    aa=0;
                }
                else{
                    aa-=kk;
                    bb+=kk;
                    kk=0;
                } 
            }
            if(cc>dd){
                if(dd<=kk){
                    kk-=dd;
                    cc+=dd;
                    dd=0;
                }
                else{
                    dd-=kk;
                    cc+=kk;
                    kk=0;
                }
            }
            else{
               if(cc<=kk){
                    kk-=cc;
                    dd+=cc;
                    cc=0;
                }
                else{
                    cc-=kk;
                    dd+=kk;
                    kk=0;
                } 
            }
            ans = max(ans,abs(aa-bb)+abs(cc-dd));
        }
       return ans;
    }
};