class Solution {
public:
    int change(int amount, vector<int>& coins) {


        // in these type of problem we always go with remaining sum !!!

        int n=coins.size();

        vector<int> prev(amount+1,0);

        prev[0]=1;

        // most important thing !!!!
        for(int s=coins[0];s<=amount;s++){
            // basically if 5 is achievable then 10 is also achievable because we are using the same coin !!!
            prev[s]=prev[s-coins[0]];
        }

        // if our base case is 0th index then we use till ind i 
        // if our base case is nth index then we use starting from ind i 

        // here dp[i] represents till ind i how many times we will be able to achieve the target !!!

        for(int i=1;i<n;i++){
            vector<int> curr(amount+1,0);
            curr[0]=1;
            for(int target=1;target<=amount;target++){
                int take=0;
                if(coins[i]<=target){
                    // each coin can be used multiple times so we tried to stay in curr row !!!
                    take=curr[target-coins[i]];
                }
                int nottake=prev[target];
                curr[target]=take+nottake;
            }
            prev=curr;
        }
        return prev[amount];
    }
};
