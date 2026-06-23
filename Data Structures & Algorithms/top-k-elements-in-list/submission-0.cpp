class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // unordered_map<int,int> mpp;
        // int n=nums.size();
        // // TC-N 
        // for(int i=0;i<n;i++){
        //     mpp[nums[i]]++;
        // }

        // // we will make min heap because isme min elements at top aate hai. So, whenever heap size 
        // // goes beyond K we will remove the topmost element. So, that size remain k. and at last 
        // // heap me jo elements bachenge unko ans array me print kar lenge 

        // // pq has only top and pop operation !!
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // vector<int> ans;
        // // storing pair of cnt and nums[i] !!!

        // // TC-N*logK
        // for(auto it:mpp){
        //     pq.push({it.second,it.first});
        //     if(pq.size()>k){
        //         pq.pop();
        //     }
        // }

        // // we can't itreate over heap like we do over map !!!---need to use while(!pq.empty())

        // // TC-KlogK 
        // while(!pq.empty()){
        //     ans.push_back(pq.top().second);
        //     pq.pop();
        // }
        // return ans;
// -------------------------------------------------------------------------------------------
        // using bucket sort !!!

        // map me elements store kar lo and then ek bucket banao jisme index will be 
        // acting as frequency !!!
        int n=nums.size();
        vector<int> ans;
        unordered_map<int,int> mpp;
        for(int num:nums){
            mpp[num]++;
        }

        // atmost freq of an element is n---now freq array has {{},{},{}....till n}
        // vector<vector<int>> because same freq ke jyada elements bhi ho skte hai !!!!
        vector<vector<int>> freq(n+1);

        for(auto it:mpp){
            freq[it.second].push_back(it.first);
        }

        for(int i=n;i>=0;i--){
            for(int num:freq[i]){
                ans.push_back(num);
                if(ans.size()==k){
                    return ans;
                }
            }
        }


    }
};
