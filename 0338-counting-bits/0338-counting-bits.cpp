class Solution {
    vector<int>dp;
    private:
    int one_bits(int n){
       if(n==0) return 0;
       if(dp[n]!=-1) return dp[n];
       return dp[n]=one_bits(n>>1)+(n&1);
    }
public:
    vector<int> countBits(int n) {
        dp=vector<int>(n+1,-1);
        vector<int>ans;
        for(int i=0;i<=n;i++){
            ans.push_back(one_bits(i));
        }
        return ans;
    }
};