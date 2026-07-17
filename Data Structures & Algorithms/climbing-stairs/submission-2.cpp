class Solution {
    int f(int n,vector<int>& dp){
        if(n==1 || n==2){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=f(n-1,dp)+f(n-2,dp);
    }
public:
    int climbStairs(int n) {
        // vector<int> dp(n+1,-1);
        // return f(n,dp);

        // space optimized 1-D approach uses variables 
        // each f(n) needs previous two values if we go from 1 to n !!
        int pprev=1;
        int prev=1;

        for(int i=2;i<=n;i++){
            int curr=prev+pprev;
            pprev=prev;
            prev=curr;
        }
        return prev;
    }
};
