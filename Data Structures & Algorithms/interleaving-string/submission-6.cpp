class Solution {
private:
    bool f(int i,int j,string& s1, string& s2, string& s3,vector<vector<int>>& dp){
        if(i==s1.length() && j==s2.length()){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool ans=false;
        // if s1[i] and s2[j] both matches s3[i+j] then we have to explore both possibility !!!. So, if any path returns true then we have to return true !!!
        if(i<s1.length() && s1[i]==s3[i+j]){
            ans=ans || f(i+1,j,s1,s2,s3,dp);
        }
        if(j<s2.length() && s2[j]==s3[i+j]){
            ans=ans || f(i,j+1,s1,s2,s3,dp);
        }
        return dp[i][j]=ans;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {

        int n1=s1.length();
        int n2=s2.length();

        if(n1+n2!=s3.length()){
            return false;
        }
        // we have two strings we will compare character by character
        // we need till m+1 and n+1 beacuse if s1 has been exhausted and we still have elements of s2 then it will be stored in dp[m][j]
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));

        dp[n1][n2]=1;

        for(int j=n2-1;j>=0;j--){
            if(s2[j]==s3[n1+j]){
                dp[n1][j]=dp[n1][j+1];
            }
        }

        for(int i=n1-1;i>=0;i--){
            if(s1[i]==s3[n2+i]){
                dp[i][n2]=dp[i+1][n2];
            }
        }

        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                if(s1[i]==s3[i+j]){
                    dp[i][j]=dp[i+1][j];
                }
                if(j<n2 && s2[j]==s3[i+j]){
                    dp[i][j]=dp[i][j+1];
                }
            }
        }
        return dp[0][0];
        // return f(0,0,s1,s2,s3,dp);
    }
};
