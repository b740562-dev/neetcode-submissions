class Solution {
public:
    int characterReplacement(string s, int k) {
        // we will surely have a element with max count-----we will try to replace other k elements only !!
        // count of recessive elements = total_len-dominant freq element !!!
        // we will always keep track of max freq 
        // count of recessive elements will not go beyond k if we don't decrease max  freq element 
        // beyond it's max value for which recessive cnt=k !!!!

        vector<int> freq(26,0);
        int l=0, maxlen=0, max_freq=0;
        int n=s.size();
        for(int r=0;r<n;r++){
            freq[s[r]-'A']++;
            max_freq=max(max_freq,freq[s[r]-'A']);
            while(((r-l+1)-max_freq)>k){
                freq[s[l]-'A']--;
                l++;
                for(int num:freq){
                    max_freq=max(max_freq,num);
                }
            }
            maxlen=max(maxlen,r-l+1);
        }
        return maxlen;
    }
};
