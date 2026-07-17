class Solution {
private:
    int f(int n,vector<int>& nums,vector<int>& dp){
        // n is the index
        if(n<0){
            return 0;
        }

        if(n==0){
            return nums[0];
        }
    
        if(dp[n]!=-1){
            return dp[n];
        }
        int rob=nums[n]+f(n-2,nums,dp);
        int notrob=f(n-1,nums,dp);
        // dp[n] stores till index n ke houses ka max rob !!!
        return dp[n]=max(rob,notrob);
    }
public:
    int rob(vector<int>& nums) {
        // this q is of same as take and not take ----choose to rob and not choose to rob----max of the two
        int n=nums.size();
        vector<int> dp(n,-1);
        return f(n-1,nums,dp);
    }
};
