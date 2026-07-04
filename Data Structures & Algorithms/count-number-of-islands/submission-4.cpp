class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<int> row={1,0,-1,0};
        vector<int> col={0,-1,0,1};
        // vector<vector<int>> vis(m,vector<int>(n,0));

        // queue<pair<int,int>> q;
        

        int cnt=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    // queue bahar intialise karo ya andar doesn't matter !!!
                    grid[i][j]=='0';
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    cnt+=1;
                    while(!q.empty()){
                        int r=q.front().first;
                        int c=q.front().second;
                        q.pop();
                        for(int k=0;k<4;k++){
                            int nr=r+row[k];
                            int nc=c+col[k];
                            if(nr<m && nc>=0 && nc<n && nr>=0 && grid[nr][nc]=='1'){
                                grid[nr][nc]='0';
                                q.push({nr,nc});
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};
