#include<bits/stdc++.h>
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int idx=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(idx<n && nums[idx]==target){
            return idx;
        }
        return -1;
    }
};
