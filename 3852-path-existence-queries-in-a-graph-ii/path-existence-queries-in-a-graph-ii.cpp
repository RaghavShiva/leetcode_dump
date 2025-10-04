class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<vector<int>> p(19,vector<int>(n));
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            v[i] = {nums[i],i};
        }
        vector<int>m(n);
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            m[v[i].second] = i;
        }
        for(int i=0;i<19;i++){
            for(int j=0;j<n;j++){
                if(i==0){
                    int ind = upper_bound(v.begin(),v.end(),make_pair(v[j].first+maxDiff,1e9))-v.begin();
                    p[i][j] = ind-1;
                }
                else{
                    p[i][j] = p[i-1][p[i-1][j]];
                }
            }
        }
        vector<int>ans;
        for(auto q:queries){
            int s = q[0];
            int d = q[1];
            s = m[s];
            d = m[d];
            if(s==d){
                ans.push_back(0);
                continue;
            }
            if(s>d){
                swap(s,d);
            }
            int dist=0;
            for(int i=18;i>=0;i--){
                if(p[i][s] >= d){
                    continue;
                }    
                else{
                    dist += pow(2,i);
                    s = p[i][s];
                }
            }
            
            if(dist >= pow(2,18)){
                ans.push_back(-1);
            }
            else{
                ans.push_back(dist+1);
            }
        }
        return ans;
    }
};