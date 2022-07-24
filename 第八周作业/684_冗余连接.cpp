class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //���鼯
        //makeset
        int n = edges.size();
        fa.resize(n+1);
        for(int i = 0;i<=n;i++)
            fa[i] = i;
        vector<int> ans;
        for(const auto& edg : edges)
        {
            int pt1 = edg[0];
            int pt2 = edg[1];
            //�жϵ�ǰ��������Ƿ�����ͬһ����
            if(isSameRoot(pt1,pt2))
            {
                //����ͬһ����,������Ҫɾ���ı�
                ans = edg;
            }
            //�ϲ�����
            unionset(pt1,pt2);
        }
        return ans;
    }

    bool isSameRoot(int x,int y)
    {
        x = find(x);
        y = find(y);
        return x==y;
    }

    int find(int x)
    {
        if(fa[x] == x)
            return x;
        else
            return fa[x] = find(fa[x]);
    }

    void unionset(int x,int y)
    {
        x = find(x);
        y = find(y);
        if(x != y)
            fa[x] = y;
    }

    vector<int> fa;
};