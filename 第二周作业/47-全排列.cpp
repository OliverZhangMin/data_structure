class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(),nums.end());
        vec_flag.resize(n);
        recursion(nums,0);
        return vec_ans;
    }
    void recursion(vector<int>& nums,int index)
    {
        if(index == n)
        {
            vec_ans.push_back(vec_tmp);
            return;
        }
        set<int> repeat_set;
        for(int i=0;i<n;i++)
        {
            if(vec_flag[i]==false)
            {
                if(repeat_set.find( nums[i]) == repeat_set.end())
                {
                    repeat_set.emplace( nums[i]);
                    vec_tmp.push_back( nums[i]);
                    vec_flag[i]=true;
                    recursion(nums,index+1);
                    vec_flag[i]=false;
                    vec_tmp.pop_back();
                }
                else
                    continue;
            }
        }
    }
    int n=0;
    vector<vector<int>> vec_ans;
    vector<int> vec_tmp;
    vector<bool> vec_flag;
};