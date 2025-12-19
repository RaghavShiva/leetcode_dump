#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string ss="";
        int cnt=0,t;
        for(int i=0;i<s.length();i++){
            
             t=ss.find(s[i])+1;
             ss=ss+s[i];
            if(t>0){
                t=ss.length()-1;
                cnt=max(cnt,t);
                t=ss.find(s[i])+1;
                ss=ss.substr(t);
            }
        }
       t=ss.length();
        cnt=max(cnt,t);
        return cnt;
    }
    
};