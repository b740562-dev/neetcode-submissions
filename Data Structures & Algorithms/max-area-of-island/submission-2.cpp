class Solution {
private:
    int dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int r,int c,int m,int n){
        if(r<0 || c<0 || r>=m || c>=n || vis[r][c]==1 || grid[r][c]==0){
            return 0;
        }
        // visited ko yha pe mark karo whi pe mark kar doge to base case hi fail ho jaiga !!!!
        vis[r][c]=1;
        return 1+dfs(grid,vis,r,c+1,m,n)+dfs(grid,vis,r+1,c,m,n)+dfs(grid,vis,r,c-1,m,n)+dfs(grid,vis,r-1,c,m,n);

    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // apply dfs----see how to write cleaner code !!!!
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        

        // ------------------------for bfs-------------------------------------------------------
        vector<int> row={0,1,0,-1};
        vector<int> col={1,0,-1,0};
        int maxarea=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]){
                    // for current island we have area=1 then we will find total current island area and we will
                    // compare it with max island area !!!!

                    // maxarea=max(maxarea,dfs(grid,vis,i,j,m,n));
                    int currarea=1;
                    vis[i][j]=1;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty()){
                        int r=q.front().first;
                        int c=q.front().second;
                        q.pop();
                        for(int k=0;k<4;k++){
                            int nr=r+row[k];
                            int nc=c+col[k];
                            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]){
                                vis[nr][nc]=1;
                                currarea+=1;
                                q.push({nr,nc});
                            }
                        }
                    }
                    maxarea=max(currarea,maxarea);
                }
            }
        }
        return maxarea;
    }
};
