class Solution {
public:
    void solve(string s,int open ,int close,int n,vector<string>& ans) {
        // answer complete?
        if(open == n && close == n){
            ans.push_back(s);
            return;
        }
        //'(' laga sakte h?
        if(open < n){
            solve(s + "(",open+1,close,n,ans);
        } 
        //')' laga sakte h?
        if(close < open){
            solve(s + ")",open,close+1,n,ans);
        }
    }
    vector<string>generateParenthesis(int n){
        vector<string>ans;
        solve("",0,0,n,ans);
        return ans;
    }
};