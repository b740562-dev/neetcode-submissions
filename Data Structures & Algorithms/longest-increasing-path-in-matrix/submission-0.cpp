class Solution {
    int f(int r,int c,vector<vector<int>>& dp,vector<vector<int>>& matrix,vector<int>& row,vector<int>& col,int m,int n){

        if(dp[r][c]!=-1){
            return dp[r][c];
        }

        int maxi=1;

        for(int i=0;i<4;i++){
            int nr=r+row[i];
            int nc=c+col[i];
            if(nr>=0 && nr<m && nc>=0 && nc<n && matrix[nr][nc]>matrix[r][c]){
                maxi=max(maxi,1+f(nr,nc,dp,matrix,row,col,m,n));
            }
        }

        return dp[r][c]=maxi;

    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int m=matrix.size(), n=matrix[0].size();

        int maxi=0;

        vector<vector<int>> dp(m,vector<int>(n,-1));

        vector<int> row={0,1,0,-1};
        vector<int> col={1,0,-1,0};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                maxi=max(maxi,f(i,j,dp,matrix,row,col,m,n));
            }
        }

        return maxi;
    }
};
