class Solution {
public:
    bool isPalindrome(string s) {
        string t="";
        for(char c:s){
            if(isalnum(c)){
                t+=tolower(c);
            }
        }

        int n=t.size();
        for(int i=0;i<n;i++){
            if(t[i]!=t[n-1-i]){
                return 0;
            }
        }
        return 1;
    }
};
