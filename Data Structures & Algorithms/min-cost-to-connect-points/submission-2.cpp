class Solution {
private:
    int findparent(int u,vector<int>& parent){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=findparent(parent[u],parent);
    }

    void unionbyrank(int u,int v,vector<int>& parent,vector<int>& rank){
        int pu=findparent(u,parent);
        int pv=findparent(v,parent);

        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }

        else if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }

        else{
            rank[pu]++;
            parent[pv]=pu;
        }
        
    }

    void unionbysize(int u,int v,vector<int>& parent,vector<int>& size){
        int pu=findparent(u,parent);
        int pv=findparent(v,parent);

        if(size[pu]<=size[pv]){
            size[pv]+=size[pu];
            parent[pu]=pv;
        }

        else{
            size[pu]+=size[pv];
            parent[pv]=pu;
        }

    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // we can apply prim's algorithm or kruskal's algorithm !!!!
        // let's proceed with prim's 

        // we will push in pq distance of every node with every other node
        int n=points.size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dis=abs(points[j][0]-points[i][0])+abs(points[j][1]-points[i][1]);
                // dis and kin do points ke bich me tha wo dis !!!!
                pq.push({dis,{i,j}});
            }
        }

        vector<int> parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<int> rank(n,0);
        vector<int> size(n,1);
        // i represents a point and j also represent a point !!!
        int sum=0;

        while(!pq.empty()){
            auto it=pq.top();
            int dis=it.first;
            int node1=it.second.first;
            int node2=it.second.second;
            pq.pop();
            if(findparent(node1,parent)==findparent(node2,parent)){
                continue;
            }
            sum+=dis;
            unionbyrank(node1,node2,parent,rank);
        }
        return sum;
    }
};
