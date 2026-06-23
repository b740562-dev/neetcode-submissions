class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // we need unique triplets !!---see two pointers can only be applied in a sorted array !!
        sort(nums.begin(),nums.end());

        int i=0;
        vector<vector<int>> ans;
        int n=nums.size();
        while(i<n){
            if(i!=0 && nums[i]==nums[i-1]){
                i++;
                continue;
            }
            int j=i+1, k=n-1;
            while(j<k){
                if(nums[j]+nums[k]==-nums[i]){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]){
                        j++;
                    }
                    while(j<k && nums[k]==nums[k+1]){
                        k--;
                    }
                }
                else if(nums[j]+nums[k]>-nums[i]){
                    k--;
                }
                else{
                    j++;
                }
            }
            i++;
        }
        return ans;
    }
};
