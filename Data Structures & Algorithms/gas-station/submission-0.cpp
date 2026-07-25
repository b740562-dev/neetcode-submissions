class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // we can complete the loop when total available gas > total cost
        // no need to check the entire clockwise formation !!! 
        int total_gas=0, total_cost=0;
        int n=gas.size();

        int currgas=0, start=0;
        for(int i=0;i<n;i++){
            total_gas+=gas[i];
            total_cost+=cost[i];
            currgas+=gas[i]-cost[i];
            if(currgas<0){
                currgas=0;
                start=i+1;
            }
        }
        return total_gas<total_cost ? -1 : start;
    }
};
