class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();

        vector<int>dp(n,0);
        dp[0]=0;

        for(int i =1;i<n;i++){
            dp[i] = stones[i]-stones[i-1];
        }
        int ans = dp[1];

        for(int i = 2;i<n;i++){
            ans = max(ans,stones[i]-stones[i-2]);
        }
        return ans;
    }
};