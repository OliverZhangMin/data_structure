class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=m-1;i>=0;i--)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                dp[i][j] = min(dp[i+1][j],dp[i+1][j+1])+triangle[i][j];
            }
        }
        return dp[0][0];
    }
};