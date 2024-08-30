class Solution {
public:

void dfs(vector<vector<int>>& image, int i, int j, int initialcolor,int color){
    int n=image.size();
    int m=image[0].size();
    if(i<0||j<0)
    return;
    if(i>=n || j>=m) return;
    if(image[i][j]!=initialcolor) return;
    image[i][j]=color;
    dfs(image,i-1,j,initialcolor,color);
    dfs(image,i+1,j,initialcolor,color);
    dfs(image,i,j-1,initialcolor,color);
    dfs(image,i,j+1,initialcolor,color); 
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]!=color)
         dfs(image,sr,sc,image[sr][sc],color);
    return image;
    }
};