class Solution {
public:
    double myPow(double x, int n) {
        long long N=n;
       if(n==0) return 1;
       if(n<0){
        x=1/x;
        N=-N;
       } 

       double half=myPow(x,N/2);
       if(N%2==0) {
        return half*half;
       }else{
        return x*half*half;
       }
    }
};