class Solution {
public:

    void generator(int open,int close,string bracket ,vector<string>&ans){
        if(open==0&&close==0){
            ans.push_back(bracket);
            return;
        }
        if(open>0)generator(open-1,close,bracket+"(",ans);
        if(close>open)generator(open,close-1,bracket+")",ans);
    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        generator(n,n,"",ans);
        return ans;
    }
};