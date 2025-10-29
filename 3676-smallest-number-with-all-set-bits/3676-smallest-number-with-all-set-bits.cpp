class Solution {
public:
    int smallestNumber(int n) {
        int temp = 0;
        while (n > 0) {
            n /= 2;
            temp++;
        }
       
        int ans = 1;
        while (temp--) {
            ans *= 2;
        }
        return ans - 1;
    }
};