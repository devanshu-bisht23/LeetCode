class Solution {
public:


    int isPossible(int day, vector<int>& bloomDay,int m, int k){

        int count = 0, res = 0;

        for(int i: bloomDay){

            if(i <= day){
                count++;
            }else{
                res += count/k;
                count = 0;
            }
        }

        res += count/k;

        if(res>=m){
            return 1;
        }else{
            return 0;
        }
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int l=INT_MAX, r=INT_MIN, res;

        for(long long i:bloomDay){   
            if(i < l){
                l = i;
            }
            if(i>r){
                r = i;
            }
        }

        if( (long long)m*k > bloomDay.size() ) return -1;  
         
        while(l<=r){

            int mid = l + (r-l)/2; 

            if(isPossible(mid, bloomDay, m, k)){
                res = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }

        }
        return res;
    }
};