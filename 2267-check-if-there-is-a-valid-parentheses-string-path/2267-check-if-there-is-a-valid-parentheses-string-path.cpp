class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    bool solve(vector<vector<char>>& grid, int i, int j, int balance) {
        // Balance negative means invalid
        if (balance < 0)
            return false;

        // End cell
        if (i == m - 1 && j == n - 1) {
            return balance == 0;
        }

        // Already calculated
        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];

        // Move Down
        bool down = false;
        if (i + 1 < m) {
            int newBalance = balance +
                (grid[i + 1][j] == '(' ? 1 : -1);

            down = solve(grid, i + 1, j, newBalance);
        }

        // Move Right
        bool right = false;
        if (j + 1 < n) {
            int newBalance = balance +
                (grid[i][j + 1] == '(' ? 1 : -1);

            right = solve(grid, i, j + 1, newBalance);
        }

        return dp[i][j][balance] = down || right;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Valid parentheses string must have even length
        if ((m + n - 1) % 2 != 0)
            return false;

        dp.assign(m, vector<vector<int>>(
            n, vector<int>(m + n, -1)
        ));

        // Starting cell
        int balance = (grid[0][0] == '(' ? 1 : -1);

        return solve(grid, 0, 0, balance);
    }
};