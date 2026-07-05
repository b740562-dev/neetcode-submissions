class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // V nodes hai and sare edges ko milake E edges store honge to O(V+E) is SC !!!

        // push in pq node connected with k !!
        vector<int> dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        vector<vector<pair<int,int>>> adj(n+1);

        // insert in pq source node only !!
        for(auto it:times){
            int src=it[0];
            int dest=it[1];
            int wt=it[2];
            adj[it[0]].push_back({it[1],wt});
        }

        // pushing kth node and time=0 !!
        pq.push({0,k});
        dist[k]=0;

        int time=0;

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int dis=it.first;
            for(auto it:adj[node]){
                int adjnode=it.first;
                int edwt=it.second;
                if(dis+edwt<dist[adjnode]){
                    pq.push({dis+edwt,adjnode});
                    dist[adjnode]=dis+edwt;
                }
            }
        }

        for(int i=1;i<=n;i++){
            // if any node is not visited till now return -1 !!!
            if(dist[i]==INT_MAX){
                return -1;
            }
            // max time in which all nodes can be reached !!!
            time=max(time,dist[i]);
        }
        return time;
    }
};
