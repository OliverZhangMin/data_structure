class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size()==1)
            return 1;
        vector<int> vec_index_max_length(nums.size());  //��¼��ǰ�±��������г���
        vector<int> vec_index_max_count(nums.size());   //��¼��ǰ������г��ȵĸ���
        vec_index_max_length[0] = 1;
        vec_index_max_count[0]  = 1;
        for(int i=1;i<nums.size();i++)
        {
            int max_len = 0;
            for(int j=0;j<i;j++)
            {
                if(nums[j] < nums[i])
                    max_len = max(max_len,vec_index_max_length[j]);
            }
            vec_index_max_length[i] = max_len +1;
            //����������ȵĸ����ж���
            int count = 0;
            for(int j = 0;j<i;j++)
            {
                if(nums[j] < nums[i])
                    if( vec_index_max_length[i] == vec_index_max_length[j] + 1)
                        count+=vec_index_max_count[j];
            }
            vec_index_max_count[i]=count==0?1:count;
        }
        //�ҵ����ĳ���
        int max_len  = *std::max_element(vec_index_max_length.begin(),vec_index_max_length.end());
        int res = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(vec_index_max_length[i] == max_len)
                res += vec_index_max_count[i];
        }
        return res;
    }
};