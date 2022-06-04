class Solution {
public:
    int row = 0;
    int col = 0;
    int max_area = 0;
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        row = matrix.size();
        col = matrix[0].size();
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j]=='0')
                    continue;
                int area = 0;
                FindArea(i,j,area,matrix);
                max_area = max(max_area,area);
            }
        return max_area;
    }
    void FindArea(int r,int c,int& area,vector<vector<char>>& matrix)
    {
        area = 0;
        int tmp_row_index=r;
        //先确认高度
        while((tmp_row_index<row) && (matrix[tmp_row_index][c] == '1'))
            tmp_row_index++;
        int height = tmp_row_index;
        //宽度需要实时更新
        int width = col;
        for(int i=r;i<height;i++)
        {
            for(int j=c;j<width;j++)
                if(matrix[i][j]=='0')
                {
                    width = min(width,j);
                    break;
                }
            int final_height = i- r+1;
            int final_width = width-c;
            int tmp_area = final_height * final_width;
            area=max(tmp_area,area);
        }
    }
};