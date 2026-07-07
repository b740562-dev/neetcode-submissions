class Solution {
    // k is ensuring whole word has been traversed or not !!!
    bool solve(int r, int c, int m, int n, vector<vector<char>>& board, string word, int k) {
        if (k == word.size()) {
            return 1;
        }

        // board of i and j has been marked visited !!!
        char ch=board[r][c];
        board[r][c] = '.';
        vector<int> row = {0, 1, 0, -1};
        vector<int> col = {1, 0, -1, 0};

        for (int p = 0; p < 4; p++) {
            int nr = r + row[p];
            int nc = c + col[p];
            if (nr < 0 || nc < 0 || nr >= m || nc >= n || board[nr][nc] == '.' || board[nr][nc] != word[k]) {
                continue;
            }
            if (solve(nr, nc, m, n, board, word, k+1)) {
                return true;
            }
        }
        board[r][c]=ch;
        return false;
    }

   public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (solve(i, j, m, n, board, word, 1)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
