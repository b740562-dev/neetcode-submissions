class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        queue<pair<int,pair<int,int>>> q;
        // we can simply apply dijkistra's and return dist[dst] !!!

        // wt--src--dest !!!
        q.push({0,{src,0}});
        vector<int> dist(n,INT_MAX);
        dist[src]=0;

        while(!q.empty()){

            auto it=q.front();
            q.pop();
            int stops=it.first;
            int s=it.second.first;
            int dis=it.second.second;
            // we are not allowing to go to stops more than k. So, first time we reach the destn is our ans !!!

            if(stops>k){
                continue;
            }

            for(auto it:adj[s] ){
                int adjnode=it.first;
                int edgwt=it.second;
                // always check for no. of stops less than k 
                if(dis+edgwt<dist[adjnode] && stops<=k){
                    dist[adjnode]=dis+edgwt;
                    q.push({stops+1,{adjnode,dist[adjnode]}});
                }
            }
        }

        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};
