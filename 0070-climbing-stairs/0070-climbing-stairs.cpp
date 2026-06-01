class Solution {
public:

    int f(int idx, int n, vector<int> &dp){

        if(idx == n) return 1;
        if(idx > n) return 0;

        if(dp[idx] != -1) return dp[idx];

        int one = f(idx+1,n,dp);
        int two = f(idx+2,n,dp);

        return dp[idx] = one + two;

    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return f(0,n,dp);
    }
};