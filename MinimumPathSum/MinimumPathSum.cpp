#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <limits>
using namespace std;


class Solution
{
public:
    int minPathSum(vector<vector<int> > &grid)
    {
        int m = grid.size();
        if (m <= 0)
        {
            return 0;
        }
        int n = grid[0].size();
        if (n <= 0)
        {
            return 0;
        }

        vector<int> v(m * n, -1);

        return minPathSumHelp(0, 0, m, n, 0, v, grid);
    }

    int minPathSumHelp(int i, int j, const int &m, const int &n, int sum, vector<int> &v, vector<vector<int> > &grid)
    {
        int index = i * n + j;
        if (v[index] >= 0)
        {
            return sum + v[index];
        }

        if ((i + 1) == m && (j + 1) == n)
        {
            return sum + grid[i][j];
        }

        int vmin = 0;
        int vbottom = (numeric_limits<int>::max)();
        int vright = vbottom;
        if ((i + 1) < m)
        {
            vbottom = minPathSumHelp(i + 1, j, m, n, sum + grid[i][j], v, grid);
        }

        if ((j + 1) < n)
        {
            vright = minPathSumHelp(i, j + 1, m, n, sum + grid[i][j], v, grid);
        }

        vmin = min(vbottom,  vright);
        cout << i << " " << j << " " << vbottom << " " << vright << endl;
        v[index] = vmin > 0 ? (vmin - sum) : 0;

        return vmin;
    }
};

int main()
{
    int data[] = { 2, 3, 4, 5, 6, 1};
    vector<int> v(data, data + sizeof(data) / sizeof(data[0]));
    Solution s;
    string ss = "PAYPALISHIRING";
    int data1[][3] = {{1, 0, 0},
                      {0, 1, 0},
                      {2, 0, 3}};
    vector<vector<int> > vv;
    for (int i = 0; i < 3; ++i)
    {
        vector<int> line;
        for (int j = 0; j < 3; ++j)
        {
            line.push_back(data1[i][j]);
        }
        vv.push_back(line);
    }
    cout << s.minPathSum(vv) << endl;
}
