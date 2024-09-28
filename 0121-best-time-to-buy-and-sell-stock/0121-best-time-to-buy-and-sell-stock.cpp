class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int low = prices[0];        
        for(int i = 0;i < n;i++){
            if(low > prices[i])
                low = prices[i];
            else        
                profit = max(profit,prices[i] - low);
        }
        return profit;
    }
};