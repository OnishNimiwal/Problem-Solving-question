class Solution {
public:
    map<tuple<int,int>,bool>dp;
    bool solve(int idx,string &s,map<tuple<int,int>,bool>&dp,int cnt){
        if(cnt<0)return false;
        if(idx==s.length())return cnt==0;
        auto state=make_tuple(idx,cnt);
        if(dp.count(state))return dp[state];
        if(s[idx]==')')return dp[state]=solve(idx+1,s,dp,cnt-1);
        else if(s[idx]=='(')return dp[state]=solve(idx+1,s,dp,cnt+1);
        else{
            return dp[state]=((solve(idx+1,s,dp,cnt+1)||(solve(idx+1,s,dp,cnt-1))||solve(idx+1,s,dp,cnt)));
        }
    }
    bool checkValidString(string s) {
        int n=s.length();
        dp.clear();
        return solve(0,s,dp,0);
    }
};