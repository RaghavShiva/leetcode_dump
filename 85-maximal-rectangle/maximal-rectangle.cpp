class Solution {
public:
    int solve(vector<int>v){
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
    int maximalRectangle(vector<vector<char>>& matrix) {
     int n = matrix.size();
     int m = matrix[0].size();
     vector<int>v(m,0); 
     int ans=0;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]=='0')
            v[j]=0;
            else{
                v[j]++;
            }
        }
        ans=max(ans,solve(v));
     }  
     return ans;
    }
};