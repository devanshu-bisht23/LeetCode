class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        int final = 0, bp = prices[0];

        for(int i = 1; i<n; i++){

            int x = prices[i] - bp;
            final = max(x,final);
            bp = min(prices[i],bp);

        }

        return final;

    }
};