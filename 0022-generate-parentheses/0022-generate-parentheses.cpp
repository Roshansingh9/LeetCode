class Solution {
    private:
    void solution(vector<string> &ans,string s,int open,int close,int max){
        if (s.size()==2*max){
            ans.push_back(s);
            return;
        }
        if(open<max) solution(ans,s+'(',open+1,close,max);
        if(close<open) solution(ans,s+')',open,close+1,max);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solution(ans,"",0,0,n);
        return ans;
    }
};