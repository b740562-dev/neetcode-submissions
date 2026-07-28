class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(), carry = 0;
        vector<int> ans;
        if (digits[n-1] < 9) {
            ans.push_back(digits[n-1] + 1);
        } 
        else {
            ans.push_back(0);
            carry = 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (carry==0) {
                ans.push_back(digits[i]);
            }
            else if (digits[i] < 9 && carry==1) {
                ans.push_back(digits[i]+1);
                carry=0;
            }  
            else {
                ans.push_back(0);
                carry = 1;
            }
        }
        if(carry==1){
            ans.push_back(1);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
