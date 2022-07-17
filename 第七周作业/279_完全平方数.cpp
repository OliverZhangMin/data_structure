class Solution {
public:
    int numSquares(int n) {
        //到当前数字 i 需要用到 最少几个 完全平方数
        vector<int> dp(n+1,1e9);
        dp[0] = 0;
        for(int i =1 ;i<=n;i++)
        {
            for(int j = 1;j*j <= i ;j++)
            {
                int val = j* j;
                dp[i] = min(dp[i-val]+1,dp[i]);
            }
        }
        return dp[n];
    }
};