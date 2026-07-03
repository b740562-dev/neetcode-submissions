class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // uppercase english alphabets --- obviously freq array !!
        vector<int> freq(26);

        for(char c:tasks){
            freq[c-'A']++;
        }

        // now we have count of all the cpus--we just have to think how will we be arranging them !!!
         int maxFreq = *max_element(freq.begin(), freq.end());

        int countMax = 0;
        for(int x : freq)
            if(x == maxFreq)
                countMax++;

        return max((int)tasks.size(),
                   (maxFreq - 1) * (n + 1) + countMax);

    }
};
