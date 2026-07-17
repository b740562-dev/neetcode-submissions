class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();
        
        // not achievable means 1e9 !! if written 0 then it means 0 coins required to achieve the target !!!
        vector<int> prev(amount+1,1e9);
        vector<int> curr(amount+1,1e9);

        // we can always achieve 0 target amount using 0 coins !!!
        prev[0]=0;
        for(int target=1;target<=amount;target++){
            if(target%coins[0]==0){
                prev[target]=target/coins[0];
            }
        }

        // we will fill the amount row !!!
        for(int i=1;i<n;i++){
            curr[0]=0;
            for(int target=1;target<=amount;target++){
                int take=1e9;
                int nottake=prev[target];
                // my previous approach was greedy as it favours taking max coin of each denomination but we want each sum ko achieve karne ka most efficient way 
                // greedily [1,3,4] amount = 10 !!
                // 10-4=6 6 ko achieve karne ka most efficient way is 2 3's 
                if(coins[i]<=target){
                    take=1+curr[target-coins[i]];
                }
                // whenever taking min then take has to be set to int_max !!!
                curr[target]=min(take,nottake);
            }  
            prev=curr;
        }
        return prev[amount]==1e9?-1:prev[amount];
    }
};
