class Solution {
    private:
    int reverse_num(int num){
        int new_num=0;
        while(num>0){
            new_num=new_num*10+num%10;
            num/=10;
        }
        return new_num;
    }
public:
    long long sumAndMultiply(int n) {
        int sum=0;
        int new_num=0;
        while(n>0){
           if(n%10!=0){
            new_num=new_num*10+n%10;
            sum+=n%10;
           }
           n/=10;
        }
        new_num=reverse_num(new_num);
        long long ans=(long long)new_num*sum;
        return ans;
    }
};