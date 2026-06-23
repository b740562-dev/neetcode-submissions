class Solution {
public:
    bool isPalindrome(string s) {
        // string t="";
        // for(char c:s){
        //     if(isalnum(c)){
        //         t+=tolower(c);
        //     }
        // }

        // int n=t.size();
        // // need to check only half string !!!
        // for(int i=0;i<n/2;i++){
        //     if(t[i]!=t[n-1-i]){
        //         return 0;
        //     }
        // }
        // return 1;

        // -------------------------------------------------------------------------------------
        // need to do without using extra string !!!

        // using two pointers !!!!
        int l=0, r=s.size()-1;

        while(l<r){
            while(l<r && !isalnum(s[l])){
                l++;
            }
            while(l<r && !isalnum(s[r])){
                r--;
            }
            if(tolower(s[l])!=tolower(s[r])){
                return 0;
            }
            l++;
            r--;
        }
        return 1;
    }
};
