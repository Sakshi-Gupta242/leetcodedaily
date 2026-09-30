class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int maxProfit = 0;

        for(int i =1;i<prices.size();i++){
            //aaj ke price ko sell price maan rahe h
            int sell = prices[i];

            //agar aaj sell karu to profit
            int profit = sell -buy;

            //maximum profit save karo
            maxProfit = max(maxProfit,profit);

            //agar aaj ka price aur sasta hai
            // toh future ke liy buy price update karo
            buy = min(buy,sell);        
    }
    return maxProfit;
    }
};