class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ans;
        for(int i=0;i<=rowIndex;i++){
            ans.push_back(ncr(rowIndex,i));
        }
        return ans;
    }
    int ncr(int n,int r){
        long long ans=1;
        for(int i=0;i<r;i++){
            ans=ans*(n-i);
            ans=ans/(i+1);
        }
        return (int)ans;
    }
};