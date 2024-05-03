class Solution {
public:
    bool isHappy(int n) {
        std::map<int, bool> seen;
        
        while (n != 1 && seen.find(n) == seen.end()) {
            seen[n] = true;
            n = computeNext(n);
        }
        
        return n == 1;
    }
    private:
    int computeNext(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
};