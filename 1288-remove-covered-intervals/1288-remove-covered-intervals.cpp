class Solution {
public:

    static bool comp(const vector<int> &a, const vector<int> &b){

        if(a[0] == b[0]){
            return a[1]<b[1];
        }

        return a[0]<b[0];

    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), comp);

        int i=0,j=1;
        int n = intervals.size();
        int ans = n;

        while(j<n){

            if(intervals[i][0]<=intervals[j][0] && intervals[i][1]>=intervals[j][1]){
                ans--;
                j++;
            }else if(intervals[j][0]==intervals[i][0] && intervals[j][1] >= intervals[i][1]){
                ans--;
                i=j;
                j++;
            }else{
                i=j;
                j++;
            }



        }

        return ans;

    }
};