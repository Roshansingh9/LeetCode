class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int n=prices.size();
    if(n<=1) return 0;
    int profit=0;
    int cost=prices[0];
    for(int i=0;i<n;i++){
        if(prices[i]<cost) cost=prices[i];
        profit=max(profit,prices[i]-cost);
    } 
    return profit;   
    }
};