class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int low=0, high=0;
        for(char c:s){
            if(c=='('){
                low++;
                high++;
            }
            if(c==')'){
                low--;
                high--;
            }
            if(c=='*'){
                low--;
                high++;
            }
            // can't possible to make valid string 
            if(high<0){
                return 0;
            }
            // low<0 when lots of asterik so we keep low to zero !!!
            low=max(low,0);
        }
        return low==0;
    }
};
