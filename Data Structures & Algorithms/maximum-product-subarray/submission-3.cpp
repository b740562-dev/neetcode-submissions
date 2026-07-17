class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currmaxi=1;
        int currmini=1;
        int ans=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                swap(currmaxi,currmini);
            }
            currmaxi=max(currmaxi*nums[i],nums[i]);
            currmini=min(currmini*nums[i],nums[i]);
            ans=max(ans,currmaxi);
        }
        return ans;
    }
};
