/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        // we are not allowed to keep old nodes in ans---we have to create new nodes

        if(head==nullptr){
            return nullptr;
        } 

        // aage wale nodes ko kaise copy karoge ???
        // first create all the nodes then make links !!!!
        // use hass map !!!!

        unordered_map<Node*,Node*> mpp;
        Node* temp=head;

        while(temp!=nullptr){
            // created new node which has same value as the old one !!!
            Node* newtemp=new Node(temp->val);
            mpp[temp]=newtemp;
            temp=temp->next;
        }

        temp=head;
        while(temp!=nullptr){
            if(mpp.find(temp->next)!=mpp.end()){
                mpp[temp]->next=mpp[temp->next];
            }
            else{
                mpp[temp]->next=nullptr;
            }
            if(mpp.find(temp->random)!=mpp.end()){
                mpp[temp]->random=mpp[temp->random];
            }
            else{
                mpp[temp]->random=nullptr;
            }
            temp=temp->next;
        }
        return mpp[head];
    }
};
