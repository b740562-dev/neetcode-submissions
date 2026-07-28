class Solution {
   private:
    int getnext(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

   public:
    bool isHappy(int n) {
        // unordered_set<int> hass;

        // // pheli bar check kiya to
        // while (n!=1 && hass.find(n) == hass.end()) {
        //     hass.insert(n);
        //     int sum=0;
        //     while (n) {
        //         int key = n % 10;
        //         sum += key * key;
        //         n = n / 10;
        //     }
        //     n=sum;
        // }

        // return n==1;

        // using floyd cycle detection to do in one go !!

        int slow=n;
        int fast=getnext(n);

        while(fast!=1 && fast!=slow){
            slow=getnext(slow);
            fast=getnext(getnext(fast));
        }

        return fast==1;
    }
};
