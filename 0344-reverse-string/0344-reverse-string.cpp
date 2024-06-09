class Solution {
public:
    void reverseString(vector<char>& s) {
        int sa=0;
        int e=s.size()-1;
        while(sa<e){
            swap(s[sa++],s[e--]);
        }
    }
};