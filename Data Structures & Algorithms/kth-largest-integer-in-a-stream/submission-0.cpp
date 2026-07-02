class KthLargest {
    // a variable will be defined as class variable if  it is expected to be used in the 
    // non constructor functions !!!
private:
    int k;
    priority_queue<int,vector<int>,greater<int>> pq;
public:
    // Kth largest is a constructor function !!!!
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int it:nums){
            pq.push(it);
            if(pq.size()>k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        // it is possible ki nums.size()<k in that case k elements abhi tak insert hi nhi hue nums me 
        // so no sense in popping elements
        if(pq.size()>k){
            pq.pop();
        }
        return pq.top();
    }
};
