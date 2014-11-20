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
    int uniquePaths(int m, int n)
    {
        if (m <= 0 || n <= 0)
        {
            return 0;
        }
        vector<int> v(m * n, -1);

        int count = 0;
        uniquePathsHelp(0, 0, m, n, count, v);

        return count;
    }

    void uniquePathsHelp(int i, int j, const int &m, const int &n, int &count, vector<int> &v)
    {
        if (v[i * n + j] > 0)
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

        if ((i + 1) < m)
        {
            uniquePathsHelp(i + 1, j, m, n, count, v);
        }

        if ((j + 1) < n)
        {
            uniquePathsHelp(i, j + 1, m, n, count, v);
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
    cout << s.uniquePaths(3, 3) << endl;
}
