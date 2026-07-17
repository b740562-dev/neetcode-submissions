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
        // vector<int> dp(n+1,-1);
        // return f(n,dp,cost);

        int pprev=0;
        int prev=0;
        for(int i=2;i<=n;i++){
            int curr=min(prev+cost[i-1],pprev+cost[i-2]);
            pprev=prev;
            prev=curr;
        }
        return prev;
    }
};
