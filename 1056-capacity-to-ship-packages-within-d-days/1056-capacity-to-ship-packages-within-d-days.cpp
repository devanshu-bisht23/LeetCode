class Solution {
public:

    int isLeast(vector<int>& weights, int days, int mid){

        int sum = 0, day = 1;

        for(int i=0; i<weights.size(); i++){
            
            if(weights[i]>mid) return 0;

            if(sum + weights[i]>mid){
                day++;
                sum = weights[i];
            }else{
                sum+=weights[i];
            }

        }

        if(day<=days){
            return 1;
        }else{
            return 0;
        }

    }

    int shipWithinDays(vector<int>& weights, int days) {
        
        int l = INT_MAX, r = 0, res;

        for(int i: weights){
            l = min(l,i);
            r+=i;
        }

        while(l<=r){

            int mid = l + (r-l)/2;

            if(isLeast(weights, days, mid)){
                res = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }

        }
    return res;
    }
};