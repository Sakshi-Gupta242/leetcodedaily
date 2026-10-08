class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        int x2 = 1;
        int x1 = 2;

        for (int i = 3; i <= n; i++) {
            int curr = x1 + x2;
            x2 = x1;
            x1 = curr;
        }

        return x1;
    }
};