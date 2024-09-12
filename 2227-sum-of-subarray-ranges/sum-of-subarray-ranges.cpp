class Solution {
public:
     long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>nse(n),pse(n);
        stack<int>st;
      
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
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
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty())
            pse[i]=-1;
            else
            pse[i]=st.top();
            st.push(i);
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            ans=ans+(nse[i]-i)*1ll*(i-pse[i])*arr[i];
        }
        return ans;
    }
    long long sumSubarrayMax(vector<int>& arr) {
        int n = arr.size();
        vector<int>nge(n),pge(n);
        stack<int>st;
      
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            if(st.empty())
            nge[i]=n;
            else
            nge[i]=st.top();
            st.push(i);
        }
        while(!st.empty())
        st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(st.empty())
            pge[i]=-1;
            else
            pge[i]=st.top();
            st.push(i);
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            ans=ans+(nge[i]-i)*1ll*(i-pge[i])*arr[i];
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long mn,mx;
        mn=sumSubarrayMins(nums);
        mx=sumSubarrayMax(nums);
        return mx-mn;
    }
};