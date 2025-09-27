class Solution {
public:
    double area(double a, double b, double c){
        double area = 0.0;
        double s = (a+b+c)/2.0;
        area = sqrt(s*(s-a)*(s-b)*(s-c));
        return area;
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double ans=0.0;
        for(int i=0;i<n;i++){
            int a1 = points[i][0];
            int b1 = points[i][1];
            for(int j=i+1;j<n;j++){
                int a2 = points[j][0];
                int b2 = points[j][1];
                for(int k=j+1;k<n;k++){
                    int a3 = points[k][0];
                    int b3 = points[k][1];
                    double a = 1.0*sqrt(pow(abs(a1-a2),2)+pow(abs(b1-b2),2));
                    double b = sqrt(pow(abs(a1-a3),2)+pow(abs(b1-b3),2));
                    double c = sqrt(pow(abs(a3-a2),2)+pow(abs(b3-b2),2));
                    ans = max(ans,area(a,b,c));
                }
            }
        }
        return ans;
    }
};