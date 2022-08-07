class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        //集合保存当前框内的数值
        int n = nums.size();
        int i =0;
        while(i<k && i<n)
        {
            q.push(make_pair(nums[i],i));
            i++;
        }
        ans.push_back(q.top().first);
        for(;i<n;i++)
        {
            q.push(make_pair(nums[i],i));
            while(!q.empty() && q.top().second<=(i-k))
                q.pop();
            ans.push_back(q.top().first);
        }
        return ans;
    }
    priority_queue<pair<int,int>> q;
};