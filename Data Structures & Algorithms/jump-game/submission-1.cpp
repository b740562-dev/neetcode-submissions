class Solution {
public:
    bool canJump(vector<int>& nums) {
        // if nums[i]=k then we can make at max jump of k length !!
        int n=nums.size();
        // we can take max jump of i+nums[i] !!!
        int maxjump=0;
        for(int i=0;i<n;i++){
            if(i>maxjump){
                return 0;
            }
            maxjump=max(maxjump,i+nums[i]);
        }
        return 1;
    }
};
