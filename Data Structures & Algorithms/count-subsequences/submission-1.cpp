class Solution {

    int f(int i,int j,vector<vector<int>>& dp,string& s, string& t){
        // if target is empty string then it is always achievable !!!
        if((i==0 && j==0) || j==0){
            return 1;
        }
        if(i==0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int take=0;
        if(s[i-1]==t[j-1]){
            take=f(i-1,j-1,dp,s,t);
        }
        int nottake=f(i-1,j,dp,s,t);
        return dp[i][j]=take+nottake;
    }

public:
    int numDistinct(string s, string t) {

        int n1=s.length(), n2=t.length();

        if(n1<n2){
            return 0;
        }

        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        dp[0][0]=1;
        

        for(int i=1;i<=n1;i++){
            // till any position of s there exist only one way to achieve empty string t which is to not take anything !!!
            dp[i][0]=1;
            for(int j=1;j<=n2;j++){
                int take=0;
                if(s[i-1]==t[j-1]){
                    take=dp[i-1][j-1];
                }
                int nottake=dp[i-1][j];
                dp[i][j]=take+nottake;
            }
        }

        return dp[n1][n2];
        // return f(n1,n2,dp,s,t);
    }
};
