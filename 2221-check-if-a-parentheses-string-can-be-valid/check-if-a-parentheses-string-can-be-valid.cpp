class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n%2){
            return false;
        }
        queue<int>q;
        stack<int>st;
        for(int i = 0; i < n; i++){
            if(locked[i]=='1'){
                if(s[i]==')'){
                    if(!st.empty() && (s[st.top()]=='(')){
                        st.pop();
                    }
                    else{
                        if(!q.empty()){
                            q.pop();
                        }
                        else{
                            return false;
                        }
                    }
                }
                else{
                    st.push(i);
                }
            }
            else{
                q.push(i);
            }
        }
        vector<int> temp;
        while(!q.empty()){
            temp.push_back(q.front());
            q.pop();
        }
        reverse(temp.begin(),temp.end());
        int i=0;
        if(temp.size()<st.size()){
            return false;
        }
        while(!st.empty()){
            if(st.top()>temp[i]){
                return false;
            }
            i++;
            st.pop();
        }
        return true;
    }
};