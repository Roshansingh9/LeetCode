class Solution {
private:
    void solution(vector<vector<int>>& ans, vector<int>& sub, vector<int>& nums,
                  int target, int currsum,int index) {
        if (currsum == target) {
            ans.push_back(sub);
        } else if (currsum > target) {
            return;
        }
    for (int i = index; i < nums.size(); i++) {
        if (i > index && nums[i] == nums[i - 1])
            continue;
        sub.push_back(nums[i]);
        solution(ans, sub, nums, target, currsum + nums[i],i+1);
        sub.pop_back();
    }

}

public : vector<vector<int>>
         combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> sub;
    sort(candidates.begin(), candidates.end());
    solution(ans, sub, candidates, target, 0,0);
    return ans;
}
}
;