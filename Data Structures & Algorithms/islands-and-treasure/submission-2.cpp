class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // in place modification is being told !!!
        // all nodes having 0 will be our source nodes !!

        // since there are multiple gates therefore there are multiple sources. So, we would think about multi-source BFS !!!
        int n=grid.size(), m=grid[0].size();

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }

        vector<int> row={0,1,0,-1};
        vector<int> col={1,0,-1,0};

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nr=r+row[k];
                int nc=c+col[k];
                if(nr<0 || nr>=n || nc<0 ||nc>=m ||grid[nr][nc]!=INT_MAX){
                    continue;
                }
                // my approach compares min max however we don't need it because q is level wise 
                // traversal all the nearest nodes would have been processed before a higher dis node appear !!!

                // so simply we can check whether grid[i][j] is INT_MAX or not !!!
                grid[nr][nc]=1+grid[r][c];
                q.push({nr,nc});
            }
        }
    }
};
