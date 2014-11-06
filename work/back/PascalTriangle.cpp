#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int> > generate(int numRows)
    {
        vector<vector<int> > result;
        if (numRows <= 0)
        {
            return result;
        }

        vector<int> line;
        line.push_back(1);

        result.push_back(line);

        if (numRows == 1)
        {
            return result;
        }

        for (int i = 1; i < numRows; ++i)
        {
            vector<int> line;
            vector<int> &lastline = result[i-1];

            line.push_back(1);
            for (int j = 1; j < i; ++j)
            {
                line.push_back(lastline[j-1] + lastline[j]);
            }
            line.push_back(1);

            result.push_back(line);
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<int> > result = s.generate(5);
    int row = result.size();
    int column;
    for (int i = 0; i < row; ++i)
    {
        column = result[i].size();
        for (int j = 0; j < column; ++j)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
