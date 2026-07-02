class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // implemneting a max heap we want top 2 heaviest stones !!!
         priority_queue<int> pq;

         for(int it:stones){
            pq.push(it);
         }

         while(pq.size()>1){
            int k1=pq.top();
            pq.pop();
            int k2=pq.top();
            pq.pop();

            if(k1!=k2){
                pq.push(k1-k2);
            }
         }

         return pq.empty() ? 0 : pq.top();
    }
};
