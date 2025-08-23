class Solution {
public:

    // void insertOdd(string &ans, string num, int n){

    //     for(int i=0; i<=n; i++){
    //         ans+= num[i];
    //     }

    // }

    string largestOddNumber(string num) {
        
        int n = num.size();
        // string ans = "";
        for(int i=n-1; i>=0; i--){

            char c = num[i];
            int nums = c - '0';

            if(nums%2 != 0){
                
                return num.substr(0,i+1);
                
                // insertOdd(ans,num,i); 
                // break;
            }

        }
    // return ans;
    return "";
    }
};