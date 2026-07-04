class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // in place modification is being told !!!
        // all nodes having 0 will be our source nodes !!

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
                if(nr<0 || nr>=n || nc<0 ||nc>=m ||grid[nr][nc]==-1 || grid[nr][nc]==0){
                    continue;
                }
                else if(1+grid[r][c]<grid[nr][nc]){
                    grid[nr][nc]=1+grid[r][c];
                    q.push({nr,nc});
                }
            }
        }
    }
};
