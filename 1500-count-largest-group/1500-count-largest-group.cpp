class Solution {
public:
    int countLargestGroup(int n) {

        unordered_map<int,int> hashMap;
        int count = 0;
        

        for(int i=1; i<=n; i++){
            int digSum = dig(i); // we get digit sum here
            hashMap[digSum]++;
        }

        int x = 0;

        for(auto &i: hashMap){
            if(i.second > x){
            x = i.second;
            }
        }

        for(auto &i: hashMap){
            if(i.second == x){
                count++;
            }
        }

    return count;

    }

    int dig(int n){

        int sum = 0;

        while(n>0){
            sum += n % 10;
            n = n/10;
        }

        return sum;

    }
};