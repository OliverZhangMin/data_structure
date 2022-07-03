class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        this->lower = lower;
        this->upper = upper;
        vec_sum.push_back(0);
        long long sum=0;
        for(const auto& it : nums)
        {
            sum+=it;
            vec_sum.push_back(sum);
        }
        return RecursionPreSum(0,vec_sum.size()-1);
    }
    int RecursionPreSum(int l,int r)
    {

        if(l==r)
            return 0;
        int mid = (l+r)/2;
        int pre_count_l = RecursionPreSum(l,mid);   //左区间内满足范围的区间段个数
        int pre_count_r = RecursionPreSum(mid+1,r); //右区间内满足范围的区间段个数
        //cout <<l<<","<<r<<",pre_count_l="<<pre_count_l<<",pre_count_r="<<pre_count_r<<endl;
        int res_count = pre_count_l + pre_count_r;  
        
        int lower_index = mid+1;    //用来确定最小值的区间点
        int upper_index = mid+1;    //用来确定最大值的区间点
        int i = l;  //前缀和差值基准点
        while(i<=mid)
        {
            while(lower_index<=r && vec_sum[lower_index] - vec_sum[i] < lower) 
                lower_index++;
            while(upper_index<=r && vec_sum[upper_index] - vec_sum[i] <= upper)
                upper_index++;
            //cout << "满足的区间:"<<lower_index<<""<<upper_index<<endl;
            res_count += (upper_index-lower_index);
            i++;
        }

        //对前缀和排序，排序对原始数组无影响，针对前缀和的排序只是为了方便使用双指针确认lower~upper的范围
        //至于前缀和数组排序后会和原始数据的前缀和会对应不上，这并不重要，此时只是为了确认区间个数，所以相对关系不重要，只要能确认个数即可
        int tmp_array_size = r-l+1;
        long long* tmp_array  =new long long[tmp_array_size];
        //归并排序
        int x_l = l;
        int x_r = mid+1;
        int p = 0;
        while(x_l<=mid || x_r <=r)
        {
            if(x_l>mid)
                    tmp_array[p++]=vec_sum[x_r++];
            else if(x_r>r)
                    tmp_array[p++]=vec_sum[x_l++];
            else
            {
                if(vec_sum[x_l] < vec_sum[x_r])
                    tmp_array[p++]=vec_sum[x_l++];
                else
                    tmp_array[p++]=vec_sum[x_r++];
            }
        }

        for(int k =0;k<tmp_array_size;k++)
            vec_sum[l+k]=tmp_array[k];
        // for(const auto& it : vec_sum)
        //     cout << it<<",";
        // cout <<endl;
        delete[] tmp_array; 
        return res_count;
    }

    int lower=0;
    int upper=0;
    vector<long long> vec_sum;
};