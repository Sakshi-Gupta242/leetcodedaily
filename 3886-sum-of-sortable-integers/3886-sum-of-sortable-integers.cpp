class Solution {
public:
    int sortableIntegers(vector<int>& nums) {

        int n = nums.size();

        // prefix maximum
        vector<int> prefMax(n + 1, 0);

        for(int i = 0; i < n; i++) {
            prefMax[i + 1] = max(prefMax[i], nums[i]);
        }

        // suffix minimum
        vector<int> suffMin(n + 1, 1e9);

        for(int i = n - 1; i >= 0; i--) {
            suffMin[i] = min(suffMin[i + 1], nums[i]);
        }

        // prefix count of normal descents
        vector<int> prefDrop(n, 0);

        for(int i = 1; i < n; i++) {
            prefDrop[i] = prefDrop[i - 1];

            if(nums[i - 1] > nums[i]) {
                prefDrop[i]++;
            }
        }

        // check whether k is sortable
        auto check = [&](int k) {

            for(int start = 0; start < n; start += k) {

                int end = start + k - 1;

                // block ke andar kitne descents hain
                int drops = prefDrop[end] - prefDrop[start];

                // last element -> first element
                // kyunki block circular hai
                if(nums[end] > nums[start]) {
                    drops++;
                }

                // 1 se zyada descent hua
                // to rotation se sorted nahi ban sakta
                if(drops > 1) {
                    return false;
                }

                // current block ka maximum
                // next blocks ke minimum se bada nahi hona chahiye
                if(prefMax[start] > suffMin[start]) {
                    return false;
                }
            }

            return true;
        };

        int ans = 0;

        // sirf divisors check karne hain
        for(int k = 1; k <= n / k; k++) {

            if(n % k == 0) {

                // k divisor hai
                if(check(k)) {
                    ans += k;
                }

                // doosra divisor
                int other = n / k;

                if(other != k && check(other)) {
                    ans += other;
                }
            }
        }

        return ans;
    }
};
