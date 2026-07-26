class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {

        // if any num in triplet is > value of target present at that index we return -1
        unordered_set<int> hass;

        for(auto it:triplets){
            int i=0;
            while(i<3){
                if(it[i]>target[i]){
                    break;
                }
                i++;
            }
            // i=3 means safe triplet 
            if(i==3){
                for(int k=0;k<3;k++){
                    if(it[k]==target[k]){
                        // we have to insert index not the val as val can be same like target=[5,5,5]
                        hass.insert(k);
                    }
                }
            }
        }

        return hass.size()==3 ? 1 : 0;

    }
};
