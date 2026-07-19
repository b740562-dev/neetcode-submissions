class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        // return f(0,1,dp,prices);

        // recursion function call me jo indices dete hai whi par tabulation end hota hai----recursion is top down, tabulation is bottom up !!!

        // vector<int> curr(2,0);
        // vector<int> next(2,0);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j==1){
                    dp[i][j]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else{
                    // if we sold today we will directly jump to i+2 !!!
                    dp[i][j]=max(prices[i]+dp[i+2][1],dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};
