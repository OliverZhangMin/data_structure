class comp
{
public:
    bool operator()(pair<int,int>& l,pair<int,int>& r)
    {
        return l.second < r.second;
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        for(int i=0;i<k;i++)
            q.push(make_pair(i,nums[i]));
        vector<int> vec_res;
        vec_res.push_back(q.top().second);
        for(int i=k;i<nums.size();i++)
        {
            q.push(make_pair(i,nums[i]));
            while(!q.empty() && q.top().first <= (i-k))
                q.pop();
            vec_res.push_back(q.top().second);
        }
        return vec_res;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,comp> q;
};