class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {

        // using kahn's algo to return the order 
        vector<int> indegree(V);
        vector<int> order;
        vector<vector<int>> adj(V);
        queue<int> q;

        for(auto it:edges){
            indegree[it[0]]++;
            adj[it[1]].push_back(it[0]);
        }

        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node=q.front();
            order.push_back(node);
            q.pop();
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        if(order.size()!=V){
            return {};
        }
        return order;
    }
};
