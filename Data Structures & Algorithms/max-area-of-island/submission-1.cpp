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

        int maxarea=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]){
                    // for current island we have area=1 then we will find current island area after each island area we will
                    // compare it with max island area !!!!
                    maxarea=max(maxarea,dfs(grid,vis,i,j,m,n));
                }
            }
        }
        return maxarea;
    }
};
