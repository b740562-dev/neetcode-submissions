class Solution {
public:
    bool canFinish(int numcourses, vector<vector<int>>& arr) {
        // directed graph---a can be accessed only through b

        // see we have to detect cycle in directed graph we will think of toposort----apply both bfs and dfs 

        // bfs uses indegree

        // always in cycle detection pro

        // numcourses stores no. of nodes !!!
        vector<vector<int>> adj(numcourses);
        vector<int> indegree(numcourses);
        queue<int> q;

        // for array we can use it[1] instead of it.first !!!
        for(auto it:arr){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        } 

        for(int i=0;i<numcourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        // instead of creating a topo array to store elements we created a cnt variable to know how many elements are allowed to become part of queue !!

        // if for all elements indegree became 0 then all will be pushed on queue and cnt=numcourses !!!

        // we were able to create toposort. So, cycle does not exist. So, it's possible to finish all courses !!!

        int cnt=0;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        return numcourses==cnt;

    }
};
