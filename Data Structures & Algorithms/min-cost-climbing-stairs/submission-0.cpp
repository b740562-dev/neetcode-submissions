class Solution {
private:
    int f(int n,vector<int>& dp,vector<int>& cost){
        // 
        if(n==0 || n==1){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];   
        }
        return dp[n]=min(f(n-1,dp,cost)+cost[n-1],f(n-2,dp,cost)+cost[n-2]);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // we want to reach the nth index
        int n=cost.size(); 
        vector<int> dp(n+1,-1);
        return f(n,dp,cost);
    }
};
