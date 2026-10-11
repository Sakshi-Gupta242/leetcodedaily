
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        // 1-based index se check karo
        for (int i = 1; i <= n; i++) {

            // agar i, n ko divide karta hai
            if (n % i == 0) {
                
                // nums[i-1] because C++ indexing 0-based hai
                ans += nums[i - 1] * nums[i - 1];
            }
        }

        return ans;
    }
};

