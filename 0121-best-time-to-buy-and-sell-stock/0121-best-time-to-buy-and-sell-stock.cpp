class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int cp=prices[0];
        int mini=0;
        for(int i=0;i<n;i++){
          mini=max(mini,prices[i]-cp);
          cp=min(cp,prices[i]);
        }
        return mini;
    }
};