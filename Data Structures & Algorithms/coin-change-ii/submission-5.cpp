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


        // in these type of problem we always go with remaining sum !!!

        int n=coins.size();

        // starting from ind i how much times amount is achieved !!!
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        dp[n][0]=1;

        for(int i=n-1;i>=0;i--){
            dp[i][0]=1;
            for(int target=1;target<=amount;target++){
                int take=0;
                if(coins[i]<=target){
                    // sum formed 
                    take=dp[i][target-coins[i]];
                }
                int nottake=dp[i+1][target];
                dp[i][target]=take+nottake;
            }
        }
        return dp[0][amount];

        // return f(0,amount,coins,0,dp);

    }
};
