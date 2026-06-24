class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int maxi=0;
        int buy=arr[0];
        int n=arr.size();
        for(int i=1;i<n;i++){
            int profit=arr[i]-buy;
            maxi=max(maxi,profit);
            // if any day stock value is less than our current buy value then we will choose to buy on
            // this day 
            if(arr[i]<buy){
                buy=arr[i];
            }
        }
        return maxi;
    }
};
