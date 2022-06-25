class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        //1.先二分确定行
        int left = 0,right = row-1,r=0;
        if(row == 1)
            r = 0;
        else
        {
            while(left < right)
            {
                int mid = (left+right+1)/2;
                if(matrix[mid][0] > target)
                    right = mid-1;
                else
                    left = mid;
            }
            r = right;
        }
        //cout << "r="<<r<<endl;
        //2.二分确定列
        left =0;
        right = col-1;
        while(left <= right)
        {
            int mid = (left+right)/2;
            if(matrix[r][mid] == target)
                return true;
            else if(matrix[r][mid] > target)
                right = mid-1;
            else
                left = mid+1;
        }
        return false;
    }
};