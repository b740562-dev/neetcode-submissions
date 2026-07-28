class Solution {
    double f(double x,int n){
        if(n==0){
            return 1;
        }
        if(n==1){
            return x;
        }
        double a=f(x,n/2);
        if(n%2!=0){
            return x*a*a;
        }
        return a*a;
    }
public:
    double myPow(double x, int n) {
        // dp indices must be integer !!!
        if(n<0){
            return f(1/x,-n);
        }
        return f(x,n);
    }
};
