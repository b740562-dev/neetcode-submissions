class Solution {
private:
void next_permutation(vector<int>& nums){
    int n=nums.size();
    int index=-1;
    for(int i=n-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            index=i;
            break;
        }
    }
    if(index==-1){
        reverse(nums.begin(),nums.end());
        return;
    }
    for(int i=n-1;i>index;i--){
        if(nums[i]>nums[index]){
            swap(nums[i],nums[index]);
            break;
        }
    }
    reverse(nums.begin()+index+1,nums.end());
    return;
}
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // we want all possible permutation !!!
        vector<vector<int>> ans;
        ans.push_back(nums);
        vector<int> nums2=nums;
        next_permutation(nums2);
        while(nums!=nums2){
            ans.push_back(nums2);
            next_permutation(nums2);
        }
        return ans;
    }
};
