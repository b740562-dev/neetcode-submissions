class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), time = 0;

        // obv it's a multisource bfs q---we will store all the rotten fruits at first in queue then
        // traverse

        queue<pair<int, int>> q;
        vector<int> row = {0, 1, 0, -1};
        vector<int> col = {1, 0, -1, 0};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        // we have to cnt time not the no. of fresh oranges that got rotten !!
        // we want to update time after completion of every level----remember we used to check level
        // using q.size() !!
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int nr = r + row[k];
                    int nc = c + col[k];
                    // if u get 0 or 2 continue we want to discuss 1!!!
                    if (nr < 0 || nc < 0 || nr >= n || nc >= m || grid[nr][nc] != 1) {
                        continue;
                    }
                    // level wise traversal will ensure nearby to rotten wale phele ripe ho !!
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                }
            }
            // update time only when a fruit got ripen---if there is no fruit near to ripen one then no need to update time 
            // as obv result will be -1 if no fresh fruit got ripen !!!
            if(!q.empty()){
                time++;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return time;
    }
};
