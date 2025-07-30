class Solution {
    private:
    void solution(set<vector<int>>& ans,vector<int>& nums,vector<int>& sub,int i,int size){
        if(i>=size ){
            ans.insert(sub);
            return;
        }
        solution(ans,nums,sub,i+1,size);
        sub.push_back(nums[i]);
        solution(ans,nums,sub,i+1,size);
        sub.pop_back();
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
       set<vector<int>>ans;
       vector<int> sub;
       solution(ans,nums,sub,0,nums.size());
       return vector<vector<int>>(ans.begin(),ans.end());
    }
};