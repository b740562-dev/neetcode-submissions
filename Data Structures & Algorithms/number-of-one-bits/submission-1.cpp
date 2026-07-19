class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        while(n){
            if(n&1){
                cnt++;
            }
            // left shift *2 right shift /2 !!!
            // right shift n by 1
            n=n>>1;
        }
        return cnt;
    }
};
