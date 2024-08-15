class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
     int i=0,j=0;
     for(auto a:commands){
        if(a=="UP")
        i--;
        else if(a=="DOWN")
        i++;
        else if(a=="RIGHT")
        j++;
        else
        j--;
     }   
     return i*n+j;
    }
};