class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // if repeated element frequency > n/2 → Moore's Voting applies.
        // No (just repeated at least twice) → Moore's Voting does not provide a 
        // correctness guarantee.

        // we can use floyd's cycle detection----it is valid when array size=n+1 and array 
        // contains elements from 1 to n and has exactly one duplicate
        // this q is same as finding start point of cycle !!!!

        // index 0 will never be part of cycle as elements of nums are from 1 to n !!
        int slow=nums[0], fast=nums[0];

        // obviously first time they are equal !!!!
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while (slow!=fast);

        fast=nums[0];
        while(fast!=slow){
            slow=nums[slow];
            fast=nums[fast];
        }

        return slow;
    }
};
