class Solution {
public:
    string removeOccurrences(string s, string part) {
        int m = part.size();
        int t=-1;
        while((t=s.find(part))!=string::npos){
            s=s.erase(t,m);
        }
        return s;
    }
};