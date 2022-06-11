class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int max_dgree = 0;
        unordered_map<int,int> m_dgree;
        unordered_map<int,pair<int,int>> m_index;
        //不存在时,记录一下数据 和 第一次出现的位置
        for(int i=0;i<nums.size();i++)
        {
            int val = nums[i];
            if(m_dgree.find(val) == m_dgree.end())
            { 
                m_index[val]=make_pair(i,i);
            }
            else
            {
                m_index[val].second=i;
            }
            m_dgree[val]++;
            max_dgree = max(max_dgree,m_dgree[val]);
        }
        int min_sub_range = INT32_MAX;
        for(const auto& it : m_index)
        {
            int val = it.first;
            if(m_dgree[val] != max_dgree)
                continue;
            min_sub_range = min(min_sub_range,m_index[val].second - m_index[val].first +1);
        }
        return min_sub_range;
    }
};