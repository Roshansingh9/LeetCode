class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>seen;
        for(int i=0;i<=nums.size()-1;i++){
            int remain=target-nums[i];
            if(seen.find(remain)!=seen.end()){
                return {seen[remain],i};
            }
            seen[nums[i]]=i;
        }
        return {};
    }
};