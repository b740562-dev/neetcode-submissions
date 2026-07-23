class Solution {
private:
    int f(int i,int j,string& s, string& p,vector<vector<int>>& dp){
        if(i==0 && j==0){
            return 1;
        }
        
        if(j==0){
            return 0;
        }

        if(i==0){
            if(j>=2 && p[j-1]=='*'){
                return f(0,j-2,s,p,dp);
            }
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i-1]==p[j-1] || p[j-1]=='.'){
            return dp[i][j]=f(i-1,j-1,s,p,dp);
        }

        if(p[j-1]=='*'){
            // 0 occurence of previous character
            int nottake=f(i,j-2,s,p,dp);
            int take=0;
            // dot can replace any character !!!
            if(p[j-2]==s[i-1] || p[j-2]=='.'){
                take=f(i-1,j,s,p,dp);
            }
            return dp[i][j]=take || nottake;
        }

        // not matching
        return dp[i][j]=0;

    }
public:
    bool isMatch(string s, string p) {
        
        // in string matching problems always recursion goes from bottom to top and tabulation from top to bottom !!
        int n1=s.size(), n2=p.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));

        return f(n1,n2,s,p,dp);

    }
};
