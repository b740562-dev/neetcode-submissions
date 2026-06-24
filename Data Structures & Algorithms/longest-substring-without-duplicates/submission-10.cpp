class Solution {
public:
    int lengthOfLongestSubstring(string arr) {
        // susbstring problem---sliding window!!!
        // constraint of N is 10^3. So, brute will easily pass !!!!
        int n=arr.size(), maxlen=0;
        // for(int i=0;i<n;i++){
        //     // keep a freq array
        //     // since we can have all possible characters---possible no. of characters are 2^8-1. 
        //     // So, characters can be stored simply at their ASCII value
        //     // subtracting a will lead to -ve index for people whose ASCII value is less than 'a' !
        //     vector<int> freq(256,0);
        //     for(int j=i;j<n;j++){
        //         if(freq[arr[j]]==1){
        //             break;
        //         }
        //         freq[arr[j]]=1;
        //         maxlen=max(maxlen,j-i+1);
        //     }
        // }
        // return maxlen;

        // --------------------------OPTIMAL------------------------------------------------------
        
        int l=0;
        // we need to keep track when an element is visited !!!
        // for not visited we are keeping -1 !!!
        vector<int> hass(255,-1);
        for(int r=0;r<n;r++){
            // till printing problem for substring is not asked try to solve using optimal !!
            // optimal approach says do not decrease window size from maximal value---always check for 
            // existence of window size + 1 !!!!
            if(hass[arr[r]]!=-1){
                // jahan pe bhi r index wale element ko phele dekha gya tha wha se +1 par se ab 
                // l chalu hoga !!!!

                // update only when previously visited one is part of our subarray otherwise not !!
                if(hass[arr[r]]>=l){
                    l=hass[arr[r]]+1;
                }
            }
            hass[arr[r]]=r;
            maxlen=max(maxlen,r-l+1);
        }
        return maxlen;
    }
};
