class Solution {
public:
    bool isAnagram(string s, string t) {
        int l1=s.size(),l2=t.size();
        if(l1!=l2) return false;
       sort(s.begin(),s.end());
       sort(t.begin(),t.end()); 
       
       return s==t;
    }
};