class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> count(26, 0);
        vector<bool> used(26, false);

        for (char c : s)
            count[c - 'a']++;

        string ans;

        for (char c : s) {
            count[c - 'a']--;

            if (used[c - 'a'])
                continue;

            while (!ans.empty() &&
                   ans.back() > c &&
                   count[ans.back() - 'a'] > 0) {

                used[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(c);
            used[c - 'a'] = true;
        }

        return ans;
    }
};