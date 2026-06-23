class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // one solution is to sort the array and check 
        sort(nums.begin(),nums.end());
        int n=nums.size(), cnt=0, maxi=0;
        for(int i=0;i<n;i++){
            if(i==0||nums[i]==nums[i-1]+1){
                cnt++;
                maxi=max(maxi,cnt);
            }
            else if(nums[i]==nums[i-1]){
                continue;
            }
            else{
                cnt=1;
            }
        }
        return maxi;
    }
};
