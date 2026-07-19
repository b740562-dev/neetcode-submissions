class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // can do simple xor 
        // 0^k=k !!!
        int x=0;
        for(auto &it:nums){
            x=x^it;
        }
        return x;
    }
};
