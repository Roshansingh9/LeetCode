class Solution {
    private:
    int one_bits(int n){
       int ans=0;
       while(n!=0){
        n=n&(n-1);
        ans++;
       }
       return ans;
    }
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            ans.push_back(one_bits(i));
        }
        return ans;
    }
};