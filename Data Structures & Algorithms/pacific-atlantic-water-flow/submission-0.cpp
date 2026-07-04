class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        // we will mark all cells connected to pacific ocean seperately and all cells conencted to atlantic ocean seperately !!!
        // those {i,j} that are marked for both will be taken in ans array !!!

        // MULTI-MULTI SOURCE BFS PROBLEM !!!!!!!!!!!!!!

        // always mark visited during pushing elements in the queue !!!!

        // Which cells can the ocean reach if we reverse the direction of water flow?

        vector<vector<int>> ans;

        int n=heights.size(), m=heights[0].size();

        vector<vector<int>> vis1(n,vector<int>(m,0));
        vector<vector<int>> vis2(n,vector<int>(m,0));

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            vis1[i][0]=1;
            q.push({i,0});
        }

        for(int j=0;j<m;j++){
            vis1[0][j]=1;
            q.push({0,j});
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
                if(nr<0 || nr>=n || nc<0 || nc>=m || heights[nr][nc]<heights[r][c] || vis1[nr][nc]){
                    continue;
                }
                vis1[nr][nc]=1;
                q.push({nr,nc});
            }
        }

        for(int i=0;i<n;i++){
            vis2[i][m-1]=1;
            q.push({i,m-1});
        }

        for(int j=0;j<m;j++){
            vis2[n-1][j]=1;
            q.push({n-1,j});
        }

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nr=r+row[k];
                int nc=c+col[k];
                // our flow direction is inward----opp of actual direction of flow from height to sea !!!
                if(nr<0 || nr>=n || nc<0 || nc>=m || heights[nr][nc]<heights[r][c] || vis2[nr][nc]){
                    continue;
                }
                vis2[nr][nc]=1;
                q.push({nr,nc});
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis1[i][j] && vis2[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
