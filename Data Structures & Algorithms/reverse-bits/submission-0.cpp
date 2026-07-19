class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        // reverse all the bits!!!
        for(int i=0;i<32;i++){
            ans=ans<<1;
            // last bit pe we created 0 then if n&1 is 1 then xor will make last bit pe 0 !!!
            ans=ans^(n&1);
            n=n>>1;
        }
        return ans;
    }
};
