class Solution {
public:
    long long sumAndMultiply(int n) {
        
        long sum = 0;
        string str = "";

        if (n == 0) return 0;

        while(n>0){

            if(n%10 != 0){
                sum+= n%10;
                str += to_string(n%10);
            }

            n = n/10;

        }

        reverse(str.begin(), str.end());
        return stoi(str)*sum;

    }
};