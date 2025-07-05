class Solution {
public:

    int isRight(int mid, vector<int>& piles, int h){

        double count = 0;
        for(int i: piles){
            count += ceil((double)i/mid);
        }

    if(count<=h){
        return 1;
    }else{
        return 0;
    }
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        int high = 0;
        for(int i: piles){
            if(i>high){
                high = i;
            }
        }

        int l = 1, r = high, res;

        while(l<=r){

            int mid = l + (r-l)/2;

            if(isRight(mid, piles, h)){
                res = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }

        }
    return res;
    }
};