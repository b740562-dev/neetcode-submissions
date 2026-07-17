class Solution {
public:
    int countSubstrings(string s) {
        // sare index ko centre mante hue no. of substrings check karo
        int n=s.size(); 
        int cnt=0;
        for(int i=0;i<n;i++){
            // considering each index as centre find total no. of odd and even length substrings !!!
            int l1=i, r1=i;
            while(l1>=0 && r1<n && s[l1]==s[r1]){
                cnt++;
                l1--;
                r1++;
            }
            int l2=i, r2=i+1;
            while(l2>=0 && r2<n && s[l2]==s[r2]){
                cnt++;
                l2--;
                r2++;
            }
        }
        return cnt;
    }
};
