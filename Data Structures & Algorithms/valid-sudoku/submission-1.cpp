class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // we don't have to think anything about empty positions !!!!!

        // checking all three dimensions---rows,columns,3*3!!!----to be done in single pass!!!!

        // keeping track of row no. and the value we see !!!!
        // keeping track of col no. and the value we see !!!!
        // keeping track of square in which a value is seen---row/3 and col/3 gives the square in 
        // which we saw a value !!!

        // row no., col no., square map !!!
        unordered_map<int,unordered_set<char>> row;
        unordered_map<int,unordered_set<char>> col;
        // unordered_map does not know how to hash pairs !!!---use map only !!!
        map<pair<int,int>,unordered_set<char>> square;

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    // skip this itreation !!!!
                    continue;
                }
                if(row[i].find(board[i][j]) != row[i].end() || col[j].find(board[i][j])!=col[j].end() || square[{i/3,j/3}].find(board[i][j])!=square[{i/3,j/3}].end()){
                    return 0;
                }
                // row[i] has all the elements of ith row. So, use insert instead of equal to !!!
                row[i].insert(board[i][j]);
                col[j].insert(board[i][j]);
                square[{i/3,j/3}].insert(board[i][j]);
            }
        }
        return 1;
    }
};
