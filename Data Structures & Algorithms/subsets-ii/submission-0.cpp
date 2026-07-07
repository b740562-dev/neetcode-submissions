class Solution {
    void solve(int idx,vector<vector<int>>& ans,vector<int>& arr,vector<int>& curr){
        ans.push_back(curr);
        // for loop is handling level !!!
        for(int i=idx;i<arr.size();i++){
            if(i>idx && arr[i]==arr[i-1]){
                continue;
            }
            curr.push_back(arr[i]);
            solve(i+1,ans,arr,curr);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // whenever duplicates present always sort the array first !!!!!
        // it may contain duplicates but subset should not be duplicate !!!
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0,ans,nums,curr);
        return ans;
    }
};
