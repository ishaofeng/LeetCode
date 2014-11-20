#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cctype>
#include <cmath>

using namespace std;


class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
    {
        int m = obstacleGrid.size();
        if (m <= 0)
        {
            return 0;
        }
        int n = obstacleGrid[0].size();
        if (n <= 0)
        {
            return 0;
        }

        vector<int> v(m * n, -1);

        int count = 0;
        uniquePathsHelp(0, 0, m, n, count, v, obstacleGrid);

        return count;
    }

    void uniquePathsHelp(int i, int j, const int &m, const int &n, int &count, vector<int> &v, vector<vector<int> > &obstacle)
    {
        if (obstacle[i][j] > 0)
        {
            return ;
        }
        if (v[i * n + j] >= 0)
        {
            count += v[i * n + j];
            return ;
        }
        int k = count;
        if ((i + 1) == m && (j + 1) == n)
        {
            ++count;
            return ;
        }

        if ((i + 1) < m && obstacle[i+1][j] == 0)
        {
            uniquePathsHelp(i + 1, j, m, n, count, v, obstacle);
        }

        if ((j + 1) < n && obstacle[i][j+1] == 0)
        {
            uniquePathsHelp(i, j + 1, m, n, count, v, obstacle);
        }
        v[i*n+j] = count - k;
    }
};

int main()
{
    int data[] = { 2, 3, 4, 5, 6, 1};
    vector<int> v(data, data + sizeof(data) / sizeof(data[0]));
    Solution s;
    string ss = "PAYPALISHIRING";
    int data1[][3] = {{0, 0, 0},
                      {0, 1, 0},
                      {0, 0, 0}};
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
    cout << s.uniquePathsWithObstacles(vv) << endl;
}
