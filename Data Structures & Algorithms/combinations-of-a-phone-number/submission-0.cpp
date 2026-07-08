class Solution {
   private:
    // idx1 will store curr place wale no. ka konse string tk traverse kar liya hai
    //  idx2 will store no. ka kon sa index tak traverse kara hai
    void f(int idx2, vector<string>& arr, string digits, string& curr,
           vector<string>& ans) {
        if (curr.size() == digits.size()) {
            ans.push_back(curr);
            return;
        }
        int n=arr[digits[idx2]-'0'].size();
        // for each character we will traverse from 0 !!! because idx1 was har character pe jo string hai usko start se end tak pura traverse karna 
        for (int i = 0; i < n; i++) {
            curr += arr[digits[idx2]-'0'][i];
            f(idx2+1, arr, digits, curr, ans);
            curr.pop_back();
        }
    }

   public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits==""){
            return ans;
        }
        // we need to store what string at each digit is
        vector<string> arr(10);
        arr[2] = "abc";
        arr[3] = "def";
        arr[4] = "ghi";
        arr[5] = "jkl";
        arr[6] = "mno";
        arr[7] = "pqrs";
        arr[8] = "tuv";
        arr[9] = "wxyz";
        string curr;
        f(0,arr,digits,curr,ans);
        return ans;
    }
};
