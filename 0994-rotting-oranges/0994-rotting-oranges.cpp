class Solution {
public:

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& time,
             int i, int j, int t) {

        if(i < 0 || i >= grid.size() ||
           j < 0 || j >= grid[0].size())
            return;

        if(grid[i][j] == 0)
            return;

        if(time[i][j] <= t)
            return;

        time[i][j] = t;

        dfs(grid, time, i-1, j, t+1); // up
        dfs(grid, time, i+1, j, t+1); // down
        dfs(grid, time, i, j-1, t+1); // left
        dfs(grid, time, i, j+1, t+1); // right
    }

    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> time(n, vector<int>(m, INT_MAX));

        // Rotten oranges se DFS start
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 2)
                    dfs(grid, time, i, j, 0);
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1) {

                    if(time[i][j] == INT_MAX)
                        return -1;

                    ans = max(ans, time[i][j]);
                }
            }
        }

        return ans;
    }
};