class Solution {
private:
int helper(string &word1,string &word2,int i,int j,vector<vector<int>>&dp){
    if(i<0 ){
        return j+1;
    }
    if(j<0 ){
        return i+1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(word1[i]==word2[j]){
        return helper(word1,word2,i-1,j-1,dp);
    }
    int insert_op=1+helper(word1,word2,i,j-1,dp);
    int delete_op=1+helper(word1,word2,i-1,j,dp);
    int replace_op=1+helper(word1,word2,i-1,j-1,dp);
    return dp[i][j]=min({insert_op,delete_op,replace_op});
}
public:
    int minDistance(string word1, string word2) {
        int i=word1.size();
        int j=word2.size();
        vector<vector<int>>dp(i,vector<int>(j,-1));
        return helper(word1,word2,i-1,j-1,dp);
    }
};