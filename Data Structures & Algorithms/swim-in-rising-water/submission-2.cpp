class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        // can apply directly prim's algorithm !!!
        int n=grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        vector<int> row={0,1,0,-1};
        vector<int> col={1,0,-1,0};

        pq.push({grid[0][0],{0,0}});
        int maxi=0;

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int val=it.first;
            int r=it.second.first;
            int c=it.second.second;
            vis[r][c]=1;
            maxi=max(maxi,val);
            if(r==n-1 && c==n-1){
                break;
            }
            for(int k=0;k<4;k++){
                int nr=r+row[k];
                int nc=c+col[k];
                if(nr<0 || nr>=n || nc<0 || nc>=n || vis[nr][nc]==1){
                    continue;
                }
                pq.push({grid[nr][nc],{nr,nc}});
            }
        }
        return maxi;
    }
};
