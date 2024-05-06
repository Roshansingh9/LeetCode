class Solution {
public:
    string convertToBase7(int num) {
         if (num == 0) {
            return "0";
        }
        
        string result = "";
        bool negative = num < 0;
        num = abs(num);
        
        while (num > 0) {
            int digit = num % 7;
            result = to_string(digit) + result;
            num /= 7;
        }
        
        if (negative) {
            result = "-" + result;
        }
        
        return result;
    }
};