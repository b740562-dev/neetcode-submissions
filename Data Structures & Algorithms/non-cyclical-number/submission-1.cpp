class Solution {
   public:
    bool isHappy(int n) {
        
        unordered_set<int> hass;

        // pheli bar check kiya to 
        while (n!=1 && hass.find(n) == hass.end()) {
            hass.insert(n);
            int sum=0;
            while (n) {
                int key = n % 10;
                sum += key * key;
                n = n / 10;
            }
            n=sum;
        }

        return n==1;

    }
};
