#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int> > subsets(vector<int> &s)
    {
        vector<vector<int> > result;

        sort(s.begin(), s.end());

        vector<int> line;

        subsetsHelp(s, 0, line, result);

        return result;
    }

    void subsetsHelp(vector<int> &s, int start, vector<int> &line, vector<vector<int> > &result)
    {
        if (start >= s.size())
        {
            result.push_back(line);
            return ;
        }

        subsetsHelp(s, start + 1, line, result);

        line.push_back(s[start]);
        subsetsHelp(s, start + 1, line, result);
        line.pop_back();
    }

    vector<vector<int> > subsets2(vector<int> &s)
    {
        vector<vector<int> > result = {{}};

        sort(s.begin(), s.end());

        for (int i = 0; i < s.size(); ++i)
        {
            int resultsize = result.size();
            for (int j = 0; j < resultsize; ++j)
            {
                vector<int> line = result[j];

                line.push_back(s[i]);
                result.push_back(line);

            }
        }

        return result;
    }

    /*
    vector<vector<int> > subsets3(vector<int> &s)
    {
        vector<vector<int> > result;
        sort(s.begin(), s.end());

        //总的变化可能性
        int count = 1 << s.size();
        for (int i = 0; i < count; ++i)
        {
            vector<int> line;
            for (int j = 0; j < s.size(); ++j)
            {
                if (i & (1 < j))
                {
                    line.push_back(s[j]);
                }
            }
            //检测是否存在然后加入
            line.push_back(line);
        }

    }
    */

    void print(vector<vector<int> > &data)
    {
        int row = data.size();
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < data[i].size(); ++j)
            {
                cout << data[i][j] << " ";
            }

            cout << endl;
        }
    }
};


int main()
{
    int data[] = {4, 1, 0};

    vector<int> v(data, data + sizeof(data) / sizeof(data[0]));
    Solution s;
    vector<vector<int> > result = s.subsets(v);
    cout << result.size() << endl;
    s.print(result);

    return 0;
}
