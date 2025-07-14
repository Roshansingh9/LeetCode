class Solution {
private:
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            ++start;
            --end;
        }
        return true;
    }

    void solution(vector<vector<string>>& ans, vector<string>& sub, string& s, int index) {
        if (index == s.size()) {
            ans.push_back(sub);
            return;
        }

        for (int i = index; i < s.size(); ++i) {
            if (isPalindrome(s, index, i)) {
                sub.push_back(s.substr(index, i - index + 1));
                solution(ans, sub, s, i + 1);
                sub.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> sub;
        solution(ans, sub, s, 0);
        return ans;
    }
};
