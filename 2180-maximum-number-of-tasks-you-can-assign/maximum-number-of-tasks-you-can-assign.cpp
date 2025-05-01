class Solution {
public:
    bool helper(vector<int>&v,vector<int>&w,int p, int s, int mid){
        deque<int> dq;
        int m = w.size();
        m--;
        for(int i=mid-1;i>=0;i--){
            int t = v[i];
            if(!dq.empty() && dq.front()>=t){
                dq.pop_front();
            }
            else if(m>=0 && w[m]>=t){
                m--;
            }
            else{
                while(m>=0 && w[m]+s>=t){
                    dq.push_back(w[m]);
                    m--;
                }
                if(dq.empty()||p==0){
                    return false;
                }
                dq.pop_back();
                p--;
            }
        }
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size();
        int m = workers.size();
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());
        int low = 0, high = min(n,m);

        while (low < high) {
            int mid = (low + high+1) / 2;
            if (helper(tasks, workers, pills, strength, mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};