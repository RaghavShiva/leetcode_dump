class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>nse(n),pse(n);
        stack<int>st;
        int mod=1e9+7;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty())
            nse[i]=n;
            else
            nse[i]=st.top();
            st.push(i);
        }
        while(!st.empty())
        st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty())
            pse[i]=-1;
            else
            pse[i]=st.top();
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=(ans+((nse[i]-i)*1ll*(i-pse[i])*arr[i])%mod)%mod;
        }
        return ans;
    }
};