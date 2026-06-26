class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // whenever permutation asked no. of characters and frequency of characters would be same !
        // can create wwindow frequ array 
        // dekho size()of window when exceed s1 ka size to l++ kar do !!

        // window size will be fixed as s1 ka size !!!

        int n1=s1.size(), n2=s2.size();
        if(n2<n1){
            return 0;
        }

        // if problem allows arbitary unicode strings then use map !!!!
        vector<int> freq(26,0);
        for(char c:s1){
            freq[c-'a']++;
        }

        int l=0;

        vector<int> freq2(26,0);
        for(int r=0;r<n2;r++){
            // phele store karao then check karo !!!!
            freq2[s2[r]-'a']++;
            if(r-l+1>n1){
                freq2[s2[l]-'a']--;
                l++;
            }
            if(r-l+1==n1){
                if(freq==freq2){
                    return 1;
                }
            } 
        }
        return 0;
    }
};
