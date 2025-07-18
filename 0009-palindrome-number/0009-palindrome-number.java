class Solution {
    public boolean isPalindrome(int x) {
        int y=0,a=x;
        if(x<0) return false;
        while(x>0){
            y=(x%10)+y*10;
            x/=10;
        }
        if(y==a){
            return true;
        }else{
            return false;
        }
    }
}