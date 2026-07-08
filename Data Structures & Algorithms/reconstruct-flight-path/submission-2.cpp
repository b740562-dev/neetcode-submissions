class Solution {
    bool dfs(string node,unordered_map<string,vector<pair<string,int>>>& adj,vector<int>& used,vector<string>& result,int n){
        // we want total no. of tickets !!!
        if(result.size()==n+1){
            return 1;
        }

        // phaltu me space complexity kyu badha rhe ho !!!----use & operator !!!

        for(auto &it:adj[node]){

            if(used[it.second]){
                continue;
            }

            used[it.second]=1;
            result.push_back(it.first);

            if(dfs(it.first,adj,used,result,n)){
                return 1;
            }
            used[it.second]=0;
            result.pop_back();
        }
        return 0;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<pair<string,int>>> adj;

        // storing an id for each destination of a source----because we have to visit all the nodes !!!!!
        for(int i=0;i<tickets.size();i++){
            adj[tickets[i][0]].push_back({tickets[i][1],i});
        }

        // need to maintain lexicographical order
        for(auto &it:adj){
            sort(it.second.begin(),it.second.end());
        }

        vector<int> used(tickets.size(),0);

        vector<string> result;
        result.push_back("JFK");

        dfs("JFK",adj,used,result,tickets.size());

        return result;
    }
};
