class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int n=coins.size();

        vector<int> curr(amount+1);
        vector<int> prev(amount+1);

        for(int target=0;target<=amount;target++){
            if(target%coins[0]==0){
                prev[target]=target/coins[0];
            }
            else{
                prev[target]=1e9;
            }
        }

        for(int ind=1;ind<n;ind++){
            curr[0]=0;
            for(int target=1;target<=amount;target++){
                int take=1e9;
                if(coins[ind]<=target){
                    take=1+curr[target-coins[ind]];
                }
                int nottake=prev[target];
                curr[target]=min(take,nottake);
            }
            prev=curr;
        }

        if(prev[amount]!=1e9){
            return prev[amount];
        }
        return -1;
    }
};
