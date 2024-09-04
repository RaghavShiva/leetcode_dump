class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
      int m = v.size();
        
        stack<int>st;
        int ans=0;
        for(int i=0;i<=m;i++){
            while(!st.empty() &&(i==m || v[st.top()]>=v[i])){
                int h = v[st.top()];
                st.pop();
                int w=0;
                if(st.empty())
                w=i;
                else
                w=i-st.top()-1;
                ans = max(ans,h*w);
            }
            st.push(i);
        }       
        return ans;   
    }
};