class Solution {
private:
  vector<vector<int>> generate(vector<vector<int>>& ans,vector<int>& subset,vector<int>& nums,int i,int size){
     if (i == size) {
            ans.push_back(subset);  
            return ans;
        }
    generate(ans,subset,nums,i+1,size);
    subset.push_back(nums[i]);
    generate(ans,subset,nums,i+1,size);
    subset.pop_back();
    return ans;
  }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size=nums.size();
        vector<int>subset;
        vector<vector<int>>ans;
        return generate(ans,subset,nums,0,size);
    }
};