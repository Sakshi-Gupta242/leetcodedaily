class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
         // dp[i] = amount i banane ke minimum coins
         vector<int> dp(amount+1,amount +1);

              // 0 amount banane ke liye 0 coins chahiye
              dp[0]=0;
               // 1 se amount tak har amount check karo
               for(int i =1;i<= amount;i++){
                 // har coin try karo
                 for(int coin : coins){
                      // agar coin current amount se chhota/equal hai
                      if(coin <= i){
                         // current coin lo
                    // baaki amount = i - coin
                    dp[i] = min(dp[i],dp[i-coin]+1);
                      }
                 }
               }
               //agar amount nhi ban paya 
               if (dp[amount]== amount+1)
               return -1;

               return dp[amount];        
    }
};