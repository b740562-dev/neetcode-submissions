class Solution {

    int ultimateparent(int u,vector<int>& parent){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=ultimateparent(parent[u],parent);
    }


    bool unionbyrank(int u,int v,vector<int>& rank,vector<int>& parent){
        int pu=ultimateparent(u,parent);
        int pv=ultimateparent(v,parent);

        if(pu==pv){
            return 0;
        }

        if(rank[pu]==rank[pv]){
            rank[pu]++;
            parent[pv]=pu;
        }
        else if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }
        else{
            parent[pu]=pv;
        }

        return 1;
    }

    bool unionbysize(int u,int v,vector<int>& size,vector<int>& parent){
        int pu=ultimateparent(u,parent);
        int pv=ultimateparent(v,parent);

        if(pu==pv){
            return 0;
        }

        if(size[pu]>=size[pv]){
            size[pu]+=size[pv];
            parent[pv]=pu;
        }
        else{
            size[pv]+=size[pu];
            parent[pv]=pu;
        }

        return 1;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n=edges.size();

        vector<int> parent(n+1);

        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        // rank keeps track of height of tree
        // size keeps track of no. of nodes
        vector<int> rank(n+1,0);
        vector<int> size(n+1,1);

        for(auto &it:edges){
            // if(unionbyrank(it[0],it[1],rank,parent)==0){
            //     return it;
            // }
            if(unionbysize(it[0],it[1],rank,parent)==0){
                return it;
            }
        }
        return {-1,-1};
    }
};
