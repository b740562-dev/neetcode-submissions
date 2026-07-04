class Solution {
private:
    void dfs(int r,int c,vector<vector<int>>& vis,vector<vector<char>>& grid,vector<int>& row,vector<int>& col){
        for(int k=0;k<4;k++){
            int nr=r+row[k];
            int nc=c+col[k];
            if(nr<grid.size() && nc>=0 && nc<grid[0].size() && nr>=0 && !vis[nr][nc] && grid[nr][nc]=='1'){
                vis[nr][nc]=1;
                dfs(nr,nc,vis,grid,row,col);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<int> row={1,0,-1,0};
        vector<int> col={0,-1,0,1};
        vector<vector<int>> vis(m,vector<int>(n,0));

        int cnt=0;

        // // queue<pair<int,int>> q;
        // // no need of visited array we can just use one block and mark it to '0' and check for it's connected ones to be 1
        // // but if interviewer do not want us to modify input array that we need vis array !!!
        

        // int cnt=0;

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(grid[i][j]=='1'){
        //             // queue bahar intialise karo ya andar doesn't matter !!!
        //             grid[i][j]=='0';
        //             queue<pair<int,int>> q;
        //             q.push({i,j});
        //             cnt+=1;
        //             while(!q.empty()){
        //                 int r=q.front().first;
        //                 int c=q.front().second;
        //                 q.pop();
        //                 for(int k=0;k<4;k++){
        //                     int nr=r+row[k];
        //                     int nc=c+col[k];
        //                     if(nr<m && nc>=0 && nc<n && nr>=0 && grid[nr][nc]=='1'){
        //                         grid[nr][nc]='0';
        //                         q.push({nr,nc});
        //                     }
        //                 }
        //             }
        //         }
        //     }
        // }
        // return cnt;

        // --------------------------using DFS--------------------------------------------------------
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt+=1;
                    dfs(i,j,vis,grid,row,col);
                }
            }
        }
        return cnt;
    }
};
