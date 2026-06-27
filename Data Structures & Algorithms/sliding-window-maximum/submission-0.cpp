class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // need to traverse in the fixed window !!
        int n=nums.size();

        // deque is a dobuly ended queue in which we have access to 
        // both front and back and add and removal from both takes O(1)
        // time 

        // whenever we need to find greatest and smallest in O(1) time 
        // we use monotonic stack---strictly increasing or strictly decreasing !!
        deque<int> dq;

        vector<int> ans;

        for(int i=0;i<n;i++){
            // dq is acting like monotonic stack. So, most of the time for 
            // our dream to store max element at front we are popping many elements

            // so, deque size will most of the time lesser than k !!!

            // front pe jo element hai wo next window size ke lie consider hona chahiye ya nhi !!!

            // focus on this alotttttttttttttttttttttttttt
            if(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }

            // agar incoming element greater hai back elements se to unko pop karte rho 
            while(!dq.empty() && nums[i]>nums[dq.back()]){
                dq.pop_back();
            }

            dq.push_back(i);
            // push only when size=k
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
