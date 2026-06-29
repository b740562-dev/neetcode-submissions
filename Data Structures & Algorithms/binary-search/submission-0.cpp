#include<bits/stdc++.h>
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lb=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int n=nums.size();
        if(lb==n || nums[lb]!=target){
            return -1;
        }
        return lb;
    }
};
