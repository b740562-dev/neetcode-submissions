class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();
        if (n % groupSize != 0) {
            return 0;
        }

        map<int, int> mpp;

        for (int x : hand) {
            mpp[x]++;
        }

        while(!mpp.empty()){
            //mpp.begin() is an itreator and we want first value stored at that itreator!!
            int start=mpp.begin()->first;
            for(int i=start;i<start+groupSize;i++){
                if(mpp.find(i)==mpp.end()){
                    return 0;
                }
                mpp[i]--;
                if(mpp[i]==0){
                    mpp.erase(i);
                }
            }
        }

        return 1;
    }
};
