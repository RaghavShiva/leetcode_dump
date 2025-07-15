class Solution {
public:
    bool isValid(string word) {
        int n=word.size();
        if(n<3)
        return 0;
        bool f=false,t=false;
        for(int i=0;i<n;i++){
            if(!((word[i]>47 && word[i]<58)||(word[i]>64&&word[i]<91)||(word[i]>96&&word[i]<123)))
            return false;
            if((word[i]>64&&word[i]<91)||(word[i]>96&&word[i]<123)){
                if(word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u'||word[i]=='A'||word[i]=='E'||word[i]=='I'||word[i]=='O'||word[i]=='U')
                f=true;
                else
                t=true;
            }
        }
        return f&&t;
    }
};