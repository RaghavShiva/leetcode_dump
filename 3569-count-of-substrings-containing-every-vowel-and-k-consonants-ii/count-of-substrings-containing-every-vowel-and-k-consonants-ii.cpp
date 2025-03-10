class Solution {
public:
    long long solve(string &word,int k){
        int n=word.size();
        long long ans=0;
        vector<int>v(5,0);
        int l=0;
        int j=0;
        for(int i=0;i<n;i++){
            while((l<k || !(v[0] && v[1]&& v[2]&& v[3]&& v[4]))&&j<n){
                 if(word[j]=='a'){
                v[0]++;
            }
            else if(word[j]=='e'){
                v[1]++;
            }
           else if(word[j]=='i'){
                v[2]++;
            }
            else if(word[j]=='o'){
                v[3]++;
            }
           else if(word[j]=='u'){
                v[4]++;
            }
            else
            l++;
            j++;
            }
            if(l>=k){
                 if(v[0] && v[1]&& v[2]&& v[3]&& v[4])
                 ans+=(n-j)+1ll;
            }
            if(word[i]=='a'){
                v[0]--;
            }
            else if(word[i]=='e'){
                v[1]--;
            }
            else if(word[i]=='i'){
                v[2]--;
            }
           else if(word[i]=='o'){
                v[3]--;
            }
           else if(word[i]=='u'){
                v[4]--;
            }
            else
            l--;
        }
        return ans;
        
    }
    long long countOfSubstrings(string word, int k) {
        long long c=solve(word,k);
        c-=solve(word,k+1);
      return c;
     
        
    }
};