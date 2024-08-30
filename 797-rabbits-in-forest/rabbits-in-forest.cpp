class Solution {
public:
    int numRabbits(vector<int>& answers) {
       map<int,int>count;
       int n=answers.size();
       for(int i=0;i<n;i++){
        count[answers[i]]++;
       }
       int ans=0;
       for(auto x:count){
        ans+=(ceil(x.second*1.0/(x.first+1))*(x.first+1));
       }
       return ans;
    }
};