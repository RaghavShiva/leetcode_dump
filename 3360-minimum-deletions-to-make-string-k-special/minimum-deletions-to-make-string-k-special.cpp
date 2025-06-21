class Solution {
public:
    int sum(int l,int r,vector<int>v,int k){
        int s = 0;
        l--;
        int n = v.size();
        while(l>=0){
            s+=v[l];
            l--;
        }
        while(r<n){
            s+=v[r]-k;
            r++;
        }
        return s;
    }
    int minimumDeletions(string word, int k) {
        map<int,int>m;
        int n = word.size();
        for(int i=0;i<n;i++){
            m[word[i]-'a']++;
        }
        vector<int> v;
        for(auto it:m){
            v.push_back(it.second);
        }
        sort(v.begin(),v.end());
        n = v.size();
        int ans = 1e5;
        for(int i=0;i<n;i++){
            int l,r;
            r = upper_bound(v.begin(),v.end(),v[i]+k)-v.begin();
            l = sum(i,r,v,v[i]+k);
            ans = min(ans, l);
            cout<<l<<' ';
        }   
        return ans;

    }
};