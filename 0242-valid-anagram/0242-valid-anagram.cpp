class Solution {
public:
    bool isAnagram(string s, string t) {
        int size_1=s.length();
        int size_2=t.length();
        if(size_1!=size_2) return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        for(int i=0;i<size_1;i++){
            if(s[i]!=t[i]) return false;
        }
        return true;
        
    }
};