class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count=0;
        map<int,int> mp;
        for(auto x: nums)
        {
           if(x!=0) mp[x]++;
        }
       return mp.size();
    }
};