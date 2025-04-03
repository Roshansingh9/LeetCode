class Solution {
public:
    void reverse(vector<char>& s,int i,int j){
        if(i>j) return;
        swap(s[i],s[j]);
        i++;
        j--;
        reverse(s,i,j);
    }
    void reverseString(vector<char>& s) {
        int i=0;
        int j=s.size()-1;
        reverse(s,i,j);
    }
};