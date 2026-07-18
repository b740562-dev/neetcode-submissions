class Solution {
public:
    int uniquePaths(int m, int n) {
        // recursion will be ending at [m-1][n-1]. So, tabulation will start from here !!!
        // if at m-1th row then only 1 way to reach our destination !!

        vector<int> curr(n,1);


        vector<int> row={0,1};
        vector<int> col={-1,0};

        for(int r=m-2;r>=0;r--){
            // (n-1)th column has always only one path !!!!
            for(int c=n-2;c>=0;c--){
                curr[c]=curr[c]+curr[c+1];
            }
        }
        return curr[0];
    }
};
