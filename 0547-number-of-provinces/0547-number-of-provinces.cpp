class Solution {
public:
 void dfs(int i,vector<vector<int>>& a,vector<int>&vis) {
    vis[i] = 1;

    for(int j = 0;j < a.size();j++){
        if (a[i][j] == 1 && vis[j] == 0){
            dfs(j,a,vis);
        }
    }
 }
    int findCircleNum(vector<vector<int>>& a) {
    int n = a.size();
    vector<int>vis(n,0);
    int count = 0;
    for(int i = 0;i<n;i++){
        if(vis[i]==0){
         count++;
         dfs(i,a,vis);
        }
    }
   return count;
    }
    };