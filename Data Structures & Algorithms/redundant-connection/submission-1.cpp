class Solution {
private:
    int findparent(int node,vector<int>& parent){
        // we do path compression which ensures that finding ultimate parent remains a O(1) task rather than O(logN) 
        // logN because we are traversing entire tree whcih we don't want so we keep ultimate parent of every node same !!!
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findparent(parent[node],parent);
    }

    bool Unionbysize(int u,int v,vector<int>& size,vector<int>& parent){
        // pu and pv are ultimate parents of u and v !!!
        int pu=findparent(u,parent), pv=findparent(v,parent);
        if(pu==pv){
            return 0;
        }
        if(size[pu]>=size[pv]){
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
        else{
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        return 1;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        // if we find edges whose parent are same then it means they are already connected. So, it's a redundant edge we return that 
        // Union by rank and union by size 
        // nodes are from 1 to n-----so array size till n+1

        // rank represents the max no. of nodes along height !!!
        int n=edges.size();
        vector<int> size(n+1,1);
        vector<int> parent(n+1);

        for(int i=1;i<n;i++){
            parent[i]=i;
        }

        for(auto it:edges){
            if(Unionbysize(it[0],it[1],size,parent)==0){
                return it;
            }
        }
        return {-1,-1};
    }
};
