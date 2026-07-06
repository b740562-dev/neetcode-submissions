class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // uppercase english alphabets --- obviously freq array !!
        // vector<int> freq(26);

        // for(char c:tasks){
        //     freq[c-'A']++;
        // }

        // // now we have count of all the cpus--we just have to think how will we be arranging them !!!
        //  int maxFreq = *max_element(freq.begin(), freq.end());

        // int countMax = 0;
        // for(int x : freq)
        //     if(x == maxFreq)
        //         countMax++;

        // return max((int)tasks.size(),
        //            (maxFreq - 1) * (n + 1) + countMax);

// -------------------------------------------------------------------------------------------------------------
        // we want cpu used maximum at top----max pq !!!
        priority_queue<int> pq;
        vector<int> freq(26,0);

        for(char c:tasks){
            freq[c-'A']++;
        }

        for(int i=0;i<26;i++){
            if(freq[i]>0){
                pq.push(freq[i]);
            }
        }

        int time=0;

        // we have max freq at top---so now we will see how to proceed
        while(!pq.empty()){
            // we have to finish n+1 tasks at once to again do the first task!!
            vector<int> temp;
            for(int i=0;i<=n;i++){
                // obviously pq me n+1 elements exist karna chahiye removal ke lie !!!
                if(!pq.empty()){
                    int fre=pq.top();
                    pq.pop();
                    fre--;
                    // we will process a cpu only when it's fre>0 !!!
                    temp.push_back(fre);
                }
            }
            // we had processed n+1 tasks. So, now we can again process tasks with max freq !!!
            for(auto it:temp){
                if(it>0){
                    pq.push(it);
                }
            }
            // agar ab koi element nhi hai process karne ke lie to last me jitna process kiya bus wo time add kar do !!
            if(pq.empty()){
                time+=temp.size();
            }
            // agar abhi bhi elements hai process karne ke lie to n+1 anyhow karna padega !!!
            else{
                time+=n+1;
            }
        }
        return time;
    }
};
