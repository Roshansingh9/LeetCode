class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        while (i < n && s[i] == ' ') {
            i++;
        }
        if (i == n)
            return 0;

        int flag = 1;
        if (s[i] == '-' || s[i] == '+') {
            flag = s[i] == '+' ? 1 : -1;
            i++;
        }
        long long result = 0;
        while (i < n && isdigit(s[i])) {

            result = result * 10 + (s[i] - '0');

            if (result > INT_MAX && flag == 1)
                return INT_MAX;
            if (result > (long long)INT_MAX + 1 && flag == -1)
                return INT_MIN;
            i++;
        }
        return flag * result;
    }
};