class Solution {
public:
    int uniquePaths(int m, int n) {
        // recursion will be ending at [m-1][n-1]. So, tabulation will start from here !!!
        // if at m-1th row then only 1 way to reach our destination !!

        vector<int> next(n,1);


        vector<int> row={0,1};
        vector<int> col={-1,0};

        for(int r=m-2;r>=0;r--){
            // column end has only one path !!!!
            vector<int> curr(n,1);
            for(int c=n-2;c>=0;c--){
                curr[c]=next[c]+curr[c+1];
            }
            next=curr;
        }
        return next[0];
    }
};
