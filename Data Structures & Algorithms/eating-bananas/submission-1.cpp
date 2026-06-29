class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=*max_element(piles.begin(),piles.end());

        while(low<=high){
            int curr_h=0;
            int mid=low+(high-low)/2;
            for(int i=0;i<n;i++){
                curr_h+=piles[i]/mid;
                if(piles[i]%mid!=0){
                    curr_h+=1;
                }
            }
            if(curr_h<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
