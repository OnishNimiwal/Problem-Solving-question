class Solution {
public:
    map<pair<int,int>,int>memo;
    vector<int>suffix;
    int n;
    int solve(int i,int M){
        if(i+2*M>=n){
            return suffix[i];
        }
        auto state=make_pair(i,M);
        if(memo.count(state)){
            return memo[state];
        }
        int maxstones=0;
        for(int X=1;X<=2*M;++X){
            int nextM=max(M,X);
            int curr=suffix[i]-solve(i+X,nextM);
            maxstones=max(maxstones,curr);
        }
        return memo[state]=maxstones;
    }
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        suffix.resize(n);
        memo.clear();
        suffix[n-1]=piles[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]+piles[i];
        }
        return solve(0,1);
    }
};