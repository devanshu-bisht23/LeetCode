class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int minLandEnd = INT_MAX;
        int minWaterEnd = INT_MAX;

        int n = landStartTime.size();
        int m = waterStartTime.size();

        for (int i = 0; i < n; i++) {
            minLandEnd = min(minLandEnd, landStartTime[i] + landDuration[i]);
        } // to find min duration in land arrays

        for (int j = 0; j < m; j++) {
            minWaterEnd = min(minWaterEnd, waterStartTime[j] + waterDuration[j]);
        } // to find min duration in water arrays

        int ans = INT_MAX;

        for (int j = 0; j < m; j++) { // land to water rides
            ans = min(ans, max(minLandEnd, waterStartTime[j]) + waterDuration[j]);
        }

        for (int i = 0; i < n; i++) { // water to land rides
            ans = min(ans, max(minWaterEnd, landStartTime[i]) + landDuration[i]);
        }

        return ans;

    }
};