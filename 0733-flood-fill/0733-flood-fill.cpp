class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int newColor,int orgColor) {
        //Boundary check
       if(i<0|| i>=image.size()|| j<0|| j >= image[0].size() || image[i][j] == newColor || image[i][j] != orgColor){
        return;
       }
       image[i][j] = newColor;

        dfs(image,i-1,j,newColor,orgColor);//top
         dfs(image,i,j+1,newColor,orgColor);//right
         dfs(image,i+1,j,newColor,orgColor);//bottom
           dfs(image,i,j-1,newColor,orgColor);//left
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image,int sr,int sc,int color) {
        int orgColor = image[sr][sc];
            //if same color then dont need to do anything
        if(orgColor == color){
            return image;
        }
        dfs(image, sr, sc, color , orgColor);
        return image;
    }
};