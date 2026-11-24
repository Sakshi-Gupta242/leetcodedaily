class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        // Calculate maximum possible product limit
        long long maxLcm = 1;
        int maxNum = 1;

        for (int x : nums) {
            maxLcm = lcm(maxLcm, (long long)x);
            maxNum = max(maxNum, x);
        }

        long long maxP = maxLcm * maxNum;

        for (int i = 0; i < n; i++) {

            long long product = 1;
            int g = 0;
            long long l = 1;

            for (int j = i; j < n; j++) {

                product *= nums[j];

                // Avoid integer overflow
                if (product > maxP) {
                    break;
                }

                g = gcd(g, nums[j]);
                l = lcm(l, (long long)nums[j]);

                if (product == g * l) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};