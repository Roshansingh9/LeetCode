class Solution {
public:
    vector<string> letterCombinations(string digits) {
         if (digits.empty()) return {};

        unordered_map<char, string> key = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };

        vector<string>ans;
        ans.push_back("");
        for(char digit:digits){
            vector<string> temp;
            for(char ch:key[digit]){
                for(string& s:ans){
                    temp.push_back(s+ch);
                }
            }
            ans=temp;
        }
        return ans;
    }
};