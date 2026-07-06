class Solution {
    void traverse(vector<int>& nums,vector<vector<int>>& ans,int idx,vector<int>& curr){
        if(idx<0){
            ans.push_back(curr);
            return ;
        }
        curr.push_back(nums[idx]);
        traverse(nums,ans,idx-1,curr);
        curr.pop_back();
        traverse(nums,ans,idx-1,curr);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        int n=nums.size();
        traverse(nums,ans,n-1,curr);
        return ans;
    }
};
