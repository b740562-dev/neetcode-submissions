class Solution {
public:
    int jump(vector<int>& nums) {

        // l stores the minimum one can jump and r stores the max one can jump 
        int n=nums.size();
        // we can take max jump of i+nums[i] !!!
        int l=0, r=0;
        int jumps=0;
        while(r<n-1){
            int farthest=0;
            for(int i=0;i<=r;i++){
                farthest=max(farthest,i+nums[i]);
            }
            l=r+1;
            r=farthest;
            jumps++;
        }
        return jumps;
    }
};
