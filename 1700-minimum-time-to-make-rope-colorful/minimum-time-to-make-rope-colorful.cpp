class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cnt=0,n=0,i;
        for(i=0;i<colors.length()-1;i++){
            if(colors[i]==colors[i+1]){
                if(neededTime[i]<neededTime[i+1])
                {
                    n=max(n,neededTime[i+1]);
                    
                    
                }
                else{
                     n=max(n,neededTime[i]);
                     
                }
                
            }
            else{
                cnt+=n;
                n=0;
            }
            
        }
        cnt+=n;
        n=0;
        bool f=false;
        for(i=0;i<colors.length()-1;i++){
            if(colors[i]==colors[i+1]){
            n=n+neededTime[i];
            f=true;
            }
            else if(f){
                n+=neededTime[i];
                f=false;
            }
            
        }
        if(f){
                n+=neededTime[i];
                f=false;
            }

        
        return n-cnt;
    }
};