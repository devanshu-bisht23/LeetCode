class Solution {
public:

    int isValid(string s, string p, vector<int>& removable, int mid){

        string temp = s;

        for (int i = 0; i < mid; i++) {
            temp[removable[i]] = '_';
        }

        int k = 0, j, count = 0;

        for (int i = 0; i < p.size(); i++) {
            for (j = k; j < temp.size(); j++) {
                if (p[i] == temp[j]) {
                    count++;
                    break;
                }
            }
            k = j + 1;
        }

        if(count == p.size()){
            return 1;
        }else{
            return 0;
        }

    }

    int maximumRemovals(string s, string p, vector<int>& removable) {

        int l = 1, r = removable.size(), res = 0;

        while(l<=r){

            int mid = l + (r-l)/2;

            if(isValid(s, p, removable, mid)){
                res = mid;
                l = mid + 1;
            }else{  
                r = mid - 1;
            }
        }
        
    return res;

    }
};