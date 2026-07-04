class Solution {
private:
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int r,int c,vector<int>& row,vector<int>& col,int m,int n,int& currmax){
        for(int k=0;k<4;k++){
            int nr=r+row[k];
            int nc=c+col[k];
            if(nr>=0 && nc>=0 && nr<m && nc<n && !vis[nr][nc] && grid[nr][nc]){
                currmax+=1;
                vis[nr][nc]=1;
                dfs(grid,vis,nr,nc,row,col,m,n,currmax);
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // apply dfs 
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<int> row={1,0,-1,0};
        vector<int> col={0,-1,0,1};
        int maxarea=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]){
                    int currmax=1;
                    vis[i][j]=1;
                    dfs(grid,vis,i,j,row,col,m,n,currmax);
                    maxarea=max(currmax,maxarea);
                }
            }
        }
        return maxarea;
    }
};
