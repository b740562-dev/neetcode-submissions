class Solution {
public:
    int lengthOfLongestSubstring(string arr) {
        // susbstring problem---sliding window!!!
        // constraint of N is 10^3. So, brute will easily pass !!!!
        int n=arr.size(), maxlen=0;
        for(int i=0;i<n;i++){
            // keep a freq array 
            vector<int> freq(256,0);
            for(int j=i;j<n;j++){
                if(freq[arr[j]]==1){
                    break;
                }
                freq[arr[j]]=1;
                maxlen=max(maxlen,j-i+1);
            }
        }
        return maxlen;
    }
};
