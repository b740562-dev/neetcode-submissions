class Solution {
public:
    string longestPalindrome(string s) {
        // dp[i] represents length of longest palindrome till index i 
        // we will use backtracking to get our string !!
        int maxlen=0;
        string ans="";
        int start=0;

        int n=s.size();
        for(int i=0;i<n;i++){

            int l=i, r=i;

            // for every index as start point we need to check for max len of odd and even length substring !!

            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>maxlen){
                    maxlen=r-l+1;
                    start=l;
                }
                l--;
                r++;
            }

            int l2=i, r2=i+1;
            while(l2>=0 && r2<n && s[l2]==s[r2]){
                if(r2-l2+1>maxlen){
                    maxlen=r2-l2+1;
                    start=l2;
                }
                l2--;
                r2++;
            }
        }
        return s.substr(start,maxlen);

    }
};
