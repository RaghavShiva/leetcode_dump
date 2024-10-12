class Solution {
public:
unordered_map<string,int>mpp;
vector<vector<string>>ans;
string b;
void dfs(string w,vector<string>&seq){
    if(w==b){
        reverse(seq.begin(),seq.end());
        ans.push_back(seq);
        reverse(seq.begin(),seq.end());
        return;
    }
    int t=mpp[w];
    int s=w.size();
    for(int i=0;i<s;i++){
                char w1=w[i];
				for(char c='a';c<='z';c++){
					w[i]=c;
                    if(mpp.find(w)!=mpp.end() && (mpp[w]+1) == t){
                        seq.push_back(w);
                        dfs(w,seq);
                        seq.pop_back();
                    }
                }
            	w[i]=w1;
			}
}

    vector<vector<string>> findLadders(string begin, string end, vector<string>& dict) {
      queue<string>q;
	unordered_set<string> s(dict.begin(), dict.end());
     b=begin;
        q.push(begin);
		s.erase(begin);
        int l=1;
        int n=begin.size(); 
		while(!q.empty()){
			string w=q.front();
			l=mpp[w];
			if(w==end)
			break;
			q.pop();
			for(int i=0;i<n;i++){
				char w1=w[i];
				for(char c='a';c<='z';c++){
					w[i]=c;
					if(s.find(w)!=s.end()){
						q.push(w);
						s.erase(w);
                        mpp[w]=l+1;
					}
				}
				w[i]=w1;
			}
		}
        if(mpp.find(end)!=mpp.end()){
            vector<string>seq;
            seq.push_back(end);
            dfs(end,seq);
        }
        return ans;
    }
};