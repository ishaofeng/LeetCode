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
    int minimumTotal(vector<vector<int> > &triangle)
    {
        if (triangle.size() < 0)
        {
            return 0;
        }
        int row = triangle.size();
        vector<int> v((1+row) * row / 2, -1);
        return minimumTotalHelp(triangle, 0, 0, v);
    }

    int minimumTotalHelp(vector<vector<int> > &triangle, int i, int j, vector<int> &v)
    {
        int index = (1+i) * i / 2 + j;
        if (v[index] > 0)
        {
            return v[index];
        }
        if (i == triangle.size())
        {
            return 0;
        }

        int vl = minimumTotalHelp(triangle, i + 1, j, v);
        int vr = minimumTotalHelp(triangle, i + 1, j + 1, v);

        v[index] = triangle[i][j] + min(vl, vr);
        return v[index];
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
