#include<bits/stdc++.h>
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // int lb=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int n=nums.size();
        int low=0, high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>=target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        if(low==n || nums[low]!=target){
            return -1;
        }
        return low;
    }
};
