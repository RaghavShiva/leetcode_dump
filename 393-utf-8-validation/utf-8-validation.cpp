class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        //1->1-127
        //2->192-223,128-191
        //3->224-239,128-191,128-191
        //4->240->247,128-191,128-191,128-191
        int t=1,k=1;
        for(int i=0;i<n;i++){
            if(t==1){
                if(data[i]<128){
                    t=1;
                    k=1;
                }
                else if(data[i]<192 || data[i]>247){
                    return false;
                }
                else if(data[i]<224){
                    t=2;
                    k=1;
                }
                else if(data[i]<240){
                    t=3;
                    k=1;
                }
                else{
                    t=4;
                    k=1;
                }
            }
            else{
                if(k<t){
                    if(data[i]>127 && data[i]<192){
                        k++;
                    }
                    else{
                        return false;
                    }
                }
                if(k==t){
                    t=1;
                }
            }
        }
        
        return k>=t;
    }
};