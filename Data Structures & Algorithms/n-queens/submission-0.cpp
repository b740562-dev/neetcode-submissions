class Solution {
   private:
    // placed the first queen---now we will see for the plcaement of n-1 queens !!!
    void place(vector<string>& board, int n, vector<vector<string>>& ans, int row) {
        // succesfully placed the n queens
        if (row == n) {
            ans.push_back(board);
            return;
        }
        // row we know----we will traverse all the columns to find the placement of the queen !!!
        // we can't change board size----so don't change n !!!
        for (int col = 0; col < n; col++) {
            if (isallowed(row, col, n, board)) {
                board[row][col] = 'Q';
                place(board, n, ans, row + 1);
                board[row][col] = '.';
            }
        }
        return;
    }

    bool isallowed(int r, int c, int n, vector<string>& board) {
        // only need to check above col, left diagonal, right diagonal !!!
        int col = c;
        for (int row = r - 1; row >= 0; row--) {
            col=col-1;
            if(col>=0 && board[row][col] == 'Q'){
                return 0;
            }
        }

        for (int row = r - 1; row >= 0; row--) {
            if (board[row][c] == 'Q') {
                return 0;
            }
        }

        col = c;
        for (int row = r - 1; row >= 0; row--) {
            col = col + 1;
            if(col<n){
                if (board[row][col] == 'Q') {
                    return 0;
                }
            }
        }

        return 1;
    }

   public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        // first queen can be placed anywhere in first row !!!!

        for (int j = 0; j < n; j++) {
            board[0][j] = 'Q';
            place(board, n, ans, 1);
            board[0][j] = '.';
        }

        return ans;
    }
};
