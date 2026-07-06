class MedianFinder {

    // we will keep two PQ----one to store max element from left and one to store min element from right !!
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty() || num<left.top()){
            left.push(num);
        }
        else{
            right.push(num);
        }
        // only valid thing is left.size()=right.size()+1 or left.size()=right.size();

        // problem with this is right=2 and left=1  then size=-1 
        if(right.size()>left.size()){
            left.push(right.top());
            right.pop();
        }
        else if(left.size()-right.size()>1){
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        if((left.size()+right.size())%2==0){
            return (left.top()+right.top())/2.0;
        }
        return left.top();
    }
};
