class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // MULTI-SOURCE BFS PROBLEM !!!!
        // take all edge wale O's are put it inside queue !!!
        // edge wale O's se jitne bhi O's connected hai unko vis array me mark 1 and during final traversal check 
        // vis me 1 mark hai and O hai to not updated otherwise updated !!!
        int n=board.size(), m=board[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;

        vector<int> row={0,1,0,-1};
        vector<int> col={1,0,-1,0};

        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                vis[i][0]=1;
                q.push({i,0});
            }
            if(board[i][m-1]=='O'){
                vis[i][m-1]=1;
                q.push({i,m-1});
            }
        }

        for(int j=0;j<m;j++){
            if(board[0][j]=='O'){
                vis[0][j]=1;
                q.push({0,j});
            }
            if(board[n-1][j]=='O'){
                vis[n-1][j]=1;
                q.push({n-1,j});
            }
        }

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nr=r+row[k];
                int nc=c+col[k];
                if(nr<0 || nr>=n || nc<0 || nc>=m || board[nr][nc]=='X' || vis[nr][nc]==1){
                    continue;
                }
                vis[nr][nc]=1;
                q.push({nr,nc});
            }
        }


        // all O's connected to diagonal are marked 1 

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=1 && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};
