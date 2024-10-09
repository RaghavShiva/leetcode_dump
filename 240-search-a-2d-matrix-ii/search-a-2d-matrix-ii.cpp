class Solution {
public:
    bool binary_search(vector<vector<int>>& matrix,int target,int r,int c){
        int l=0,h=c,m;
        if(r>=c){
        for(int i=0;i<=r;i++){
            l=0;
            h=c;
            while(l<=h){
                m=l+(h-l)/2;
                if(matrix[i][m]==target)
                    return true;
                if(matrix[i][m]>target)
                    h = m-1;
                else
                    l = m+1;
            }
        }
        }
        else{
        for(int i=0;i<=c;i++){
            l=0;
            h=r;
            while(l<=h){
                m=l+(h-l)/2;
                if(matrix[m][i]==target)
                    return true;
                if(matrix[m][i]>target)
                    h = m-1;
                else
                    l = m+1;
            }
        }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int r=m-1,c=n-1;
        
        if(m>1){
            int l=0,h=m-1,mid;
        while(l<=h){
             mid = (l+h)/2;
            if(matrix[mid][0]==target){
                return true;
            }
            else if(matrix[mid][0]>target){
                h = mid - 1;
                r = mid;
            }
            else
                l = mid + 1;
        }
            if(r==0)
                return false;
                if(r!=(m-1))
                  r--;
            
        }
        if(n>1){
             int l=0,h=n-1,mid;
        while(l<=h){
             mid = (l+h)/2;
            if(matrix[0][mid]==target){
                return true;
            }
            else if(matrix[0][mid]>target){
                h = mid - 1;
                c = mid;
            }
            else
                l = mid + 1;
        }
            if(c==0)
                return false;
                if(c!=(n-1))
                  c--;
        }
        if(r==0 && c==0){
            if(matrix[0][0]==target)
                return true;
            else
                return false;
        } 
    return binary_search(matrix,target,r,c);
    }
};