class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str_res = strs[0];
        for(int i=1;i<strs.size();i++)
        {
            int count = 0;
            for(int j=0;j<str_res.size() && j<strs[i].size() ;j++)
            {
                if(str_res[j] == strs[i][j])
                {
                    count++;
                    continue;
                }
                else
                    break;
            }
            str_res = str_res.substr(0,count);
        }
        return str_res;
    }
};