
class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> dp(n + 1, 0);

        // dp[i] = maximum number of characters of word2
        // that can be matched using word1[i...]
        for (int i = n - 1; i >= 0; i--) {
            if (dp[i + 1] < m && word1[i] == word2[m - dp[i + 1] - 1])
                dp[i] = dp[i + 1] + 1;
            else
                dp[i] = dp[i + 1];
        }

        vector<int> ans;

        int j = 0;
        bool changed = false;

        for (int i = 0; i < n && j < m; i++) {

            // Exact match
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }

            // Use our one allowed mismatch
            else if (!changed && dp[i + 1] >= m - j - 1) {
                ans.push_back(i);
                j++;
                changed = true;
            }
        }

        if (j == m)
            return ans;

        return {};
    }
};
