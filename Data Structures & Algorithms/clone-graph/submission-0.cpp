/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // we are given first node and it's neighbours
        if(node==nullptr){
            return node;
        }
        // map stores old node and uske corresponding new nodes !!
        unordered_map<Node*,Node*> mpp;
        // i am pushing old neighbours in the new nodes 
        // first create all the nodes then push the nieghbours 
        Node* start=new Node(node->val);
        mpp[node]=start;

        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            Node* curr=q.front();
            q.pop();
            for(auto it:curr->neighbors){
                if(mpp.find(it)==mpp.end()){
                    Node* next=new Node(it->val);
                    mpp[it]=next;
                    q.push(it);
                }
            }
        }

        // now we will make connections 
        for(auto it:mpp){
            Node* old=it.first;
            Node* now=it.second;
            for(auto it:old->neighbors){
                now->neighbors.push_back(mpp[it]);
            }
        }
        return start;
    }
};
