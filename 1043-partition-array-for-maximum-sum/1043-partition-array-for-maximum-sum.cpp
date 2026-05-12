class Solution {
public:
    int solve(int i, int k, vector<int>& arr, vector<int>& dp) {
        int n = arr.size();

        if (i == n) return 0;

        if (dp[i] != -1) return dp[i];

        int len = 0; int maxi = 0; int ans = 0;

        for (int j = i; j < min(i + k, n); j++) {
            len++;
            maxi = max(maxi, arr[j]);

            int sum = (len * maxi) + solve(j + 1, k, arr, dp);

            ans = max(ans, sum);
        }

        return dp[i] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> dp(n, -1);

        return solve(0, k, arr, dp);
    }
};