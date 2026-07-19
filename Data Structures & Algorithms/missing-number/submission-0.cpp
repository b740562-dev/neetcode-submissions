class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // total sum-current sum
        int n=nums.size();
        int currsum=accumulate(nums.begin(),nums.end(),0);
        int totalsum=n*(n+1)/2;
        return totalsum-currsum;
    }
};
