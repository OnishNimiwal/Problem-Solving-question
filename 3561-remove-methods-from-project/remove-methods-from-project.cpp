class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,vector<int>&vis){
        vis[node]=true;
        for(auto it:adj[node]){
            if(!vis[it])dfs(it,adj,vis);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        for(auto it:invocations){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        vector<int>vis(n,false);
        dfs(k,adj,vis);
        bool reverse=true;
        for(auto it:invocations){
            int u=it[0];
            int v=it[1];
            if(!vis[u]&&vis[v]){
                reverse=false;
                break;
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!reverse||!vis[i])ans.push_back(i);
        }
        return ans;
    }
};