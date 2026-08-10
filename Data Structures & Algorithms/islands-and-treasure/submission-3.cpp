class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int m=grid.size(), n=grid[0].size();
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
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
                if(nr<0 || nc<0 || nr>=m || nc>=n || grid[nr][nc]!=INT_MAX){
                    continue;
                }
                grid[nr][nc]=1+grid[r][c];
                q.push({nr,nc});
            }
        }
    }
};
