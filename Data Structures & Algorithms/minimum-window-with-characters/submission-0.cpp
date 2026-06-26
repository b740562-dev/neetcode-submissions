class Solution {
public:
    string minWindow(string s, string t) {
        int n1=s.size(), n2=t.size();

        if(n1<n2){
            return "";
        } 
        
        // making target_freq array 
        vector<int> target_freq(128,0);
        for(char c:t){
            target_freq[c]++;
        }

        vector<int> curr_freq(128,0);

        int l=0, r=0, minlen=1e9;

        // required_unique and formed will tell how many unique characters are their in target_freq 
        // and how many of them we found in curr_freq

        int done=0, target=0;
        for(int i=0;i<128;i++){
            if(target_freq[i]>0){
                target++;
            }
        }

        int k1=0, k2=0;
        

        while(r<n1){

            // we got our first character that is present in both strings !!!
            curr_freq[s[r]]++;
            // if current char is present in target_freq with matching count then done++;
            if(target_freq[s[r]]>0 && curr_freq[s[r]]==target_freq[s[r]]){
                done++;
            }

            while(l<=r && done==target){
                if(r-l+1<minlen){
                    k1=l;
                    k2=r;
                    minlen=r-l+1;
                }
                curr_freq[s[l]]--;
                // if dropping this charac breaks our target requirement 

                if(target_freq[s[l]]>0 && curr_freq[s[l]]<target_freq[s[l]]){
                    done--;
                }
                l++;
            }
            r++;
        }

        return minlen==1e9?"":s.substr(k1,k2-k1+1);
    }
};
