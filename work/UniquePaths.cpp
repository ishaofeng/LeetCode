#include <iostream>

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

        int count = 0;
        uniquePathsHelp(0, 0, m, n, count);

        return count;
    }

    void uniquePathsHelp(int i, int j, const int &m, const int &n, int &count)
    {
        if ((i + 1) == m && (j + 1) == n)
        {
            ++count;
        }

        if ((i + 1) < m)
        {
            uniquePathsHelp(i + 1, j, m, n, count);
        }

        if ((j + 1) < n)
        {
            uniquePathsHelp(i, j + 1, m, n, count);
        }
    }
};

int main()
{
    Solution s;
    cout << "paths: " << s.uniquePaths(23, 12) << endl;
    return 0;
}
