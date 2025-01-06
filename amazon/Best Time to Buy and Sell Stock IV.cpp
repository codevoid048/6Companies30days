class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k == 0) return 0;
        //DP[day][k][buy/sell]
        vector<vector<vector<int>>> dp(n + 1,vector<vector<int>>(k + 1, vector<int>(2, 0)));
        for(int i = n - 1; i >= 0; i--){
            for(int j = 1; j <= k; j++){
                dp[i][j][1] = max(dp[i+1][j][0]-prices[i], dp[i+1][j][1]);
                dp[i][j][0] = max(prices[i]+dp[i+1][j-1][1], dp[i+1][j][0]);
            }
        }
        return dp[0][k][1];
    }
};