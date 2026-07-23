class Solution {
private:
    int f(int i,int j,vector<int>& nums2,vector<vector<int>>& dp){
        
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int maxi=0;
        // choosing the ballon to be bursted at last is the most important trick here !!!!!
        for(int ind=i;ind<=j;ind++){
            maxi=max(maxi,nums2[i-1]*nums2[ind]*nums2[j+1]+f(i,ind-1,nums2,dp)+f(ind+1,j,nums2,dp));
        }
        return dp[i][j]=maxi;

    }

public:
    int maxCoins(vector<int>& nums) {
        
        // we can choose any ballon to burst at last---represented by ind then it will have neighbours as i-1 and j+1 !!
        int n=nums.size();
        vector<int> nums2;
        nums2.push_back(1);

        for(auto &it:nums){
            nums2.push_back(it);
        }

        nums2.push_back(1);

        vector<vector<int>> dp(n+2,vector<int>(n+2,0));

        for(int i=n;i>0;i--){
            for(int j=i;j<=n;j++){
                int maxi=0;
                for(int ind=i;ind<=j;ind++){
                    maxi=max(maxi,nums2[i-1]*nums2[ind]*nums2[j+1]+dp[i][ind-1]+dp[ind+1][j]);
                }
                dp[i][j]=maxi;
            }
        }
        return dp[1][n];
        // return f(1,n,nums2,dp);

    }
};
