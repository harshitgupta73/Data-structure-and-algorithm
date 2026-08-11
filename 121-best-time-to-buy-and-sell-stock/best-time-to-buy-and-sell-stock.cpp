class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int profit = 0;
        for(int i=0;i<prices.size();i++){
            int currProfit = prices[i]-mini;
            profit=max(currProfit, profit);
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};