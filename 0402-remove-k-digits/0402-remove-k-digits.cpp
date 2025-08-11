#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for (char digit : num) {
            while (!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }
            st.push(digit);
        }

        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        
        string res;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());

     
        while (res.size() > 1 && res[0] == '0') {
            res.erase(res.begin());
        }

        return res.empty() ? "0" : res;
    }
};
