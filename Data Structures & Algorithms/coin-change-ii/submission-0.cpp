class Solution {
    int f(int ind,int amount,vector<int>& coins,int sum,vector<vector<int>>& dp){
        if(ind==coins.size() || sum>amount){
            return 0;
        }
        if(sum==amount){
            return 1;
        }

        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }

        int take=0;
        if(coins[ind]<=amount){
            take=f(ind,amount,coins,sum+coins[ind],dp);
        }

        int nottake=f(ind+1,amount,coins,sum,dp);
        return dp[ind][sum]=take+nottake;
    }
public:
    int change(int amount, vector<int>& coins) {

        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        return f(0,amount,coins,0,dp);

    }
};
