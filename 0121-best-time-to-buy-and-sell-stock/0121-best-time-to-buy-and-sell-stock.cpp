class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int maxProfit = 0;

        for(int i = 0; i < prices.size();i++){
            int sell = prices[i];

            int profit = sell-buy;
            maxProfit = max(maxProfit,profit);
            buy = min(buy,sell);
        }
        return maxProfit;      
    }
};