class Solution {
public:
    
    int fib(int n) {
       int result=0;
       if(n==0 || n==1) return n;
       result=fib(n-1)+fib(n-2);
       return result; 
    }
};