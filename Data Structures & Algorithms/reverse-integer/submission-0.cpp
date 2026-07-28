class Solution {
public:
    int reverse(int x) {
        int res=0;
        while(x!=0){
            // popping means we removed the base character !!
            int pop=x%10;
            x=x/10;

            // can't do res*10 as it goes out of bound then any random no. will be stored
            if(res>INT_MAX/10 || (res==INT_MAX/10 && pop>7)){
                return 0;
            }

            if(res<INT_MIN/10 || (res==INT_MIN/10 && pop<-8)){
                return 0;
            }

            res=res*10+pop;
        }
        return res;
    }
};
