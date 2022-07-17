class Solution {
public:
    bool canJump(vector<int>& nums) {
        //记录当前能到的最远位置
        int max_index = 0;
        for(int i=0;i<nums.size();i++)
        {
            //如果当前位置 大于 目前能到的最远位置,那么就失败
            if(i > max_index)
                return false;
            else
            {
                //根据当前下标 和 之前的最远位置,刷新最远距离
                max_index = max(max_index, i+nums[i]);
            }
        }
        return true;
    }
};