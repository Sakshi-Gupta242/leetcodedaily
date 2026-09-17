class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();
        const int INF = 1e9;

        vector<int> best(n, INF);

        int left = 0;
        int sum = 0;
        int ans = INF;

        for (int right = 0; right < n; right++) {

            sum += arr[right];

            // Window ko chhota karo
            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            // Target sum ka subarray mil gaya
            if (sum == target) {

                int len = right - left + 1;

                // Left side mein koi valid subarray hai
                if (left > 0 && best[left - 1] != INF) {
                    ans = min(ans, len + best[left - 1]);
                }

                // Current subarray ko store karo
                best[right] = len;
            }

            // Previous best bhi carry forward karo
            if (right > 0) {
                best[right] = min(best[right], best[right - 1]);
            }
        }

        if (ans == INF)
            return -1;

        return ans;
    }
};