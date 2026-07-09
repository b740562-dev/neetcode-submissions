class Solution {
private:
    vector<int> toposort(vector<vector<int>>& adj,int V){

        vector<int> indegree(V,0);
        // toposort works for multiple comoponents very well
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return ans;

    }
public:
    string foreignDictionary(vector<string>& words) {
        int n=words.size();
        // for words set freq array works far faster 
        vector<int> freq(26);

        // toposort works for multiple nodes very well !!!

        for(string s:words){
            for(char ch:s){
                freq[ch-'a']=1;
            }
        }

        vector<vector<int>> adj(26);


        for(int i=1;i<n;i++){
            string s2=words[i];
            string s1=words[i-1];
            int n1=min(s1.size(),s2.size());
            int j=0;
            while(j<n1){
                if(s1[j]==s2[j]){
                    j++;
                    continue;
                }
                adj[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
            // not valid !!!----case of ab and abcd
            if(j==n1 && s1.size()>s2.size())
                return "";
        }

        vector<int> topo=toposort(adj,26);


        string ans;
        for(auto it:topo){
            if(freq[it]==1){
                ans+=char(it+'a');
            }
        }
        // all the elements present in freq array !!!!
        int cnt=0;
        for(int x:freq)
            cnt+=x;

        if(ans.size()==cnt){
            return ans;
        }
        return "";
    }
};
