class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // if not able to find start or end word in wordlist return 0
        //push every element in set so that searching becomes easier

        // whenever min is asked in traversal we choose bfs over dfs becomes first time a result occur for sure it will be min because of level wise traversal !!!

        unordered_set<string> st;
        queue<pair<string,int>> q;

        for(auto it:wordList){
            // set always uses insert !!!
            st.insert(it);
        }

        // if can't able to find endword in st return 0 
        if(st.find(endWord)==st.end()){
            return 0;
        }

        // we push starting word and it's distance in queue then traverse !!!
        q.push({beginWord,1});

        while(!q.empty()){
            // taking everyword and check 
            string s=q.front().first;
            int dis=q.front().second;
            q.pop();
            for(int i=0;i<s.size();i++){
                string p=s;
                for(int j=0;j<26;j++){
                    p[i]=j+'a';
                    if(p==endWord){
                        return dis+1;
                    }
                    if(p!=s && st.find(p)!=st.end()){
                        q.push({p,dis+1});
                        // erasing the element p from st because dot and lot both can produce dog because lot can find dot which is unneccesary !!
                        st.erase(p);
                    }
                }
            }
        }
        return 0;
    }
};
