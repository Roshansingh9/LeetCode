class Solution {
    private:
    void helper(vector<vector<int>>& ans,vector<int>& nums,int index,vector<int>& sub){
        if (index == nums.size()) {
            ans.push_back(sub);
            return;
        }
        helper(ans,nums,index+1,sub);
        sub.push_back(nums[index]);
        helper(ans,nums,index+1,sub);
        sub.pop_back();

    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>sub;
        sort(nums.begin(), nums.end());
        helper(ans,nums,0,sub);
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};