class Solution {
private:
    void dfs(int node,vector<vector<int>>& adj,vector<int>& vis){
        vis[node]=1;
        for(auto it:adj[node]){
            // mandatory in undirected graph because from 0 we access 1 and from 1 we can again access 0 !!!
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }

public:
    int countComponents(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);
        vector<int> vis(V,0);
        int cnt=0;

        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        // jitni bar bfs traversal call hoga utne nodes !!!
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adj,vis);
            }
        }
        return cnt;
    }
};
