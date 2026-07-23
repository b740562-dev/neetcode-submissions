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
        if(s1.length()+s2.length()!=s3.length()){
            return false;
        }
        // we have two strings we will compare character by character
        // we need till m+1 and n+1 beacuse if s1 has been exhausted and we still have elements of s2 then it will be stored in dp[m][j]
        vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,-1));
        return f(0,0,s1,s2,s3,dp);
    }
};
