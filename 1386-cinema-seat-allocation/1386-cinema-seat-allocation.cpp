class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows;

        for (auto x : reservedSeats) {
            rows[x[0]] |= (1 << x[1]);
        }

        int ans = 2 * n;

        for (auto [row, mask] : rows) {
            bool left = !(mask & (1<<2) || mask & (1<<3) ||
                          mask & (1<<4) || mask & (1<<5));

            bool mid = !(mask & (1<<4) || mask & (1<<5) ||
                         mask & (1<<6) || mask & (1<<7));

            bool right = !(mask & (1<<6) || mask & (1<<7) ||
                           mask & (1<<8) || mask & (1<<9));

            ans -= 2;  // initially this row had 2

            if (left && right)
                ans += 2;
            else if (left || mid || right)
                ans += 1;
        }

        return ans;
    }
};