class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int ans = 0;
        int l=-1,r=-1,k=-1;
        for(int i=0;i<n;i++){
            if(l==-1){
                l=i;
            }
            else if(fruits[i]!=fruits[l] && r==-1){
                r=i;
            }
            else{
                if(fruits[i]==fruits[l]){
                    l=i;
                }
                else if(fruits[i]==fruits[r]){
                    r=i;
                }
                else{
                    if(l<r){
                        k = l;
                        l=r;
                        r=i;
                    }
                    else{
                        k=r;
                        r=i;
                    }
                }
            }
            ans = max(ans,max(l,r)-k);
        }
        return ans;
    }
};