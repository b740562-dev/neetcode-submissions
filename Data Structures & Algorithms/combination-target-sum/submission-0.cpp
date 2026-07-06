class Solution {
private:
    void traverse(vector<int>& nums,int target,vector<vector<int>>& ans,int idx,int& sum,vector<int>& curr){
        if(sum==target){
            ans.push_back(curr);
            return;
        }
        // previous tak ka sum>target !!!
        if(sum>target){
            return;
        }
        if(idx<0){
            return;
        }
        // u can't take
        if(nums[idx]>target){
            return ;
        }
        // u can take 
        else{
            sum+=nums[idx];
            curr.push_back(nums[idx]);
            traverse(nums,target,ans,idx,sum,curr);
            sum-=nums[idx];
            curr.pop_back();
            // can take but choosing not to take 
            traverse(nums,target,ans,idx-1,sum,curr);
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> curr;
        int sum=0;
        traverse(nums,target,ans,n-1,sum,curr);
        return ans;
    }
};
