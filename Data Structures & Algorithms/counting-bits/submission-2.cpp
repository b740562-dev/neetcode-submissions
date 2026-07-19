class Solution {
private:
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
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);

// for even number 10----n/2=5 
// 10--1010, 5---101

// for odd number 11----n/2=5
// 11---1011, 5---101
        for(int i=1;i<=n;i++){
            ans[i]=ans[i/2]+(i&1);
        }
        return ans;
    }
};
