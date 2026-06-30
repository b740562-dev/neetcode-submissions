// ds defined inside struct has access to everyone but ds defined inside class is private 

// how to define node structure !!!----isko dimag me utaar lo !!!!
struct Node{
    // see we have to remove LRU guy then we have to remove that pair from map as well and we have 
    // no way to get key from a given value !!!
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int x,int y) : key(x), val(y), next(nullptr), prev(nullptr) {}
};

class LRUCache {

private:
    int capacity;
    unordered_map<int,Node*> mpp;
    Node* dummyhead;
    Node* dummytail;

    void removenode(Node* node){
        // do not delete the node----can use node again and again because deleted node ko dusre 
        // jagah place karna hai !!!
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }

    void insertathead(Node* node){
        node->prev=dummyhead;
        node->next=dummyhead->next;
        dummyhead->next=node;
        node->next->prev=node;
    }

public:
    LRUCache(int capacity) {
        // aisa likhna hota hai !!!
        this->capacity=capacity;
        // these are already intialised in class 
        dummyhead= new Node(-1,-1);
        dummytail= new Node(-1,-1);
        dummyhead->next=dummytail;
        dummytail->prev=dummyhead;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()){
            return -1;
        }

        // this node is now most recently used node 
        removenode(mpp[key]);
        insertathead(mpp[key]);
        return mpp[key]->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            mpp[key]->val=value;
            removenode(mpp[key]);
            insertathead(mpp[key]);
            return;

        }
        Node* node=new Node(key,value);
        if(mpp.size()==capacity){
            Node* temp=dummytail->prev;
            removenode(temp);
            mpp.erase(temp->key);
            delete temp;
        }
        insertathead(node);
        mpp[key]=node;
    }
};
