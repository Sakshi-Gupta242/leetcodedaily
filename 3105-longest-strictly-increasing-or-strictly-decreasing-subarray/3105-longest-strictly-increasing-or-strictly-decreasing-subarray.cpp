class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
         int inc = 1;
         int dec = 1;
         int ans = 1;

    for (int i = 1; i < nums.size(); i++) {

        // Strictly Increasing
        if (nums[i] > nums[i - 1]) {
            inc++;
        }
        else {
            inc = 1;
        }

        // Strictly Decreasing
        if (nums[i] < nums[i - 1]) {
            dec++;
        }
        else {
            dec = 1;
        }

        // Update maximum length
        ans = max(ans, max(inc, dec));
    }

    return ans;
}
};
