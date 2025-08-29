class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        set<int> st(nums.begin(), nums.end()); 

        nums = vector<int>(st.begin(), st.end()); 

        return st.size(); 
    }
};
