class Solution {
public:
    queue<pair<int,int>> q;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        //记录点是否走过
        if(grid[0][0] == 1)return -1;
        q.emplace(make_pair(0,0));
        grid[0][0]=1;
        int depth  = 0;
        while(!q.empty())
        {
            depth++;
            //cout << "depth:"<<depth<<endl;
            int size = q.size();
            while(size)
            {
                auto [x,y] = q.front();
                q.pop();
                if(x == n-1 && y == n-1)
                    return depth;
                //grid[x][y] = 1;
                for(int i=0;i<8;i++)
                {
                    int nx = x + direct_x[i];
                    int ny = y + direct_y[i];
                    if((nx < 0 || nx>=n || ny <0 || ny >= n) || grid[nx][ny] == 1)
                        continue;
                    else{
                        q.emplace(nx,ny);
                        grid[nx][ny]=1;
                    }
                }
                size--;
            }
        }
        return -1;
    }

    const int direct_x[8]={-1,1,0,0,-1,-1,1,1};
    const int direct_y[8]={0,0,-1,1,-1,1,-1,1};
    int n =0;
};