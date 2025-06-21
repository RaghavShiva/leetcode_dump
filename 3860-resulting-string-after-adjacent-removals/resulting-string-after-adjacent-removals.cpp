class Solution {
public:
    string resultingString(string s) {
        stack<int>st;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(!st.empty() && (abs(st.top()-(s[i]-'a'))==1 || abs(st.top()-(s[i]-'a'))==25)){
                st.pop();
            }
            else{
                st.push(s[i]-'a');
            }
        }
        string ans = "";
        while(!st.empty()){
            ans += (char)(st.top()+'a');
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};