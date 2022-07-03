class Solution {
public:
    void solve(vector<vector<char>>& board) {
        //方向数组
        int dx[4]={0,0,-1,1};   //上下左右：x横坐标，y纵坐标
        int dy[4]={1,-1,0,0};
        //初始化使用情况
        m = board.size();
        n = board[0].size();
        m_use = vector<vector<bool>>(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='X' || m_use[i][j])
                    continue;
                bool b_ok = true;
                vector<pair<int,int>> vec_path; //保存搜索的O点
                //检查当前O点是否为边框部分
                if(IsBoard(i,j))
                    b_ok = false;
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                while(!q.empty())
                {
                    auto point  = q.front();
                    q.pop();
                    if(m_use[point.first][point.second])
                        continue;
                    vec_path.push_back(point);              //保存遍历的O点
                    m_use[point.first][point.second]=true;  //标记为使用过
                    for(int k=0;k<4;k++)                    //往四周遍历
                    {
                        int n_row = point.first + dy[k];
                        int n_col = point.second + dx[k];
                        if(!IsValid(board,n_row,n_col))
                            continue;
                        if(IsBoard(n_row,n_col))
                             b_ok = false;
                        q.push(make_pair(n_row,n_col));
                    }
                }
                if(b_ok) 
                {
                    for(const auto& pt : vec_path)
                        board[pt.first][pt.second]='X';
                }
            }
    }
    //O点是否是边框
    bool IsBoard(int row,int col)
    {
        if(row == 0 || row == m-1 || col ==0 || col==n-1)
            return true;
        return false;
    }
    //参数点是否有效，比如超出矩阵有效范围，点被使用过，点是X
    bool IsValid(vector<vector<char>>& board, int row,int col)
    {
        if(row < 0 || col<0 || row>=m || col>=n)
            return false;
        if(m_use[row][col])
            return false;
        if(board[row][col]=='X')
            return false;
        return true; 
    }
    int m=0;
    int n=0;
    vector<vector<bool>> m_use;
};