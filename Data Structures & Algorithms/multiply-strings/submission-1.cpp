class Solution {
public:
    string multiply(string num1, string num2) {

        if(num1=="0" || num2=="0"){
            return "0";
        }

        int n1=num1.size(), n2=num2.size();
        vector<int> temp(n1+n2,0);
        string ans="";
        
        // how we used to multiply in childhood types pura !!
        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                int mul=(num1[i]-'0')*(num2[j]-'0');
                int p1=i+j; //---- carry index 
                int p2=i+j+1;

                int sum=mul + temp[p2];

                temp[p2]=sum%10; //--at the index we store last digit !!!
                temp[p1]+=sum/10; //--at the next index we carry remaining !!
            }
        }

        // find first non zero digit to store !!
        int idx=0;
        while(idx<n1+n2 && temp[idx]==0){
            idx++;
        }

        while(idx<n1+n2){
            ans+=to_string(temp[idx]);
            idx++;
        }

        // if ans is empty 
        return ans.empty() ? "0" : ans;

    }
};
