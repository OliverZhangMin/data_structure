class Solution {
public:
    int jump(vector<int>& nums) {
        //到第i个下标所需要跳跃的最小次数
        vector<int> dp(nums.size(),0);
        dp[0] = 0;
        for(int i =1;i<nums.size();i++)
        {
            int min_jump = 1e9;
            for(int j=0;j<i;j++)
            {
                if(j+nums[j] >= i)
                    min_jump = min(min_jump,dp[j]);
            }
            dp[i]=min_jump+1;
        }
        return dp[nums.size()-1];
    }
};