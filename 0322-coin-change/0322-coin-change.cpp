class Solution {

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for (int i = 0; i <=amount; i++) {
            if (i % coins[0] == 0) {
                dp[0][i] = i / coins[0];
            } else {
                dp[0][i] = 1e7;
            }
        }
        for(int index=1;index<n;index++){
            for(int amt=1;amt<=amount;amt++){
                int not_take=dp[index-1][amt];
                int take=1e7;
                if(coins[index]<=amt){
                    take=1+dp[index][amt-coins[index]];
                }
                dp[index][amt]=min(take,not_take);

            }
        }
        

        int ans = dp[n-1][amount];
        if (ans >= 1e7) {
            return -1;
        }

        return ans;
    }
};