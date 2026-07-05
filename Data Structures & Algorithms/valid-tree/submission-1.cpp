class Solution {
public:
    bool validTree(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);
        vector<int> vis(V);

        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        queue<pair<int,int>> q;
        q.push({0,-1});
        vis[0]=1;

        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,node});
                }
                else if(it!=parent){
                    return 0;
                }
            }
        }

        // in one traversal sare nodes visit nhi hue to return 0
        for(int i=0;i<V;i++){
            if(!vis[i]){
                return 0;
            }
        }
        return 1;
    }
};
