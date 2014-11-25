#include <iostream>
#include <vector>
#include <set>
#include <cctype>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <limits>
#include <algorithm>
#include <list>
#include <utility>
#include <cstdlib>
#include <memory>
#include <string.h>
using namespace std;


class Solution
{
public:
    int numTreesHelp(int n, int buf[])
    {
        if (buf[n] > 0)
        {
            return buf[n];
        }

        if (n <= 1)
        {
            return 1;
        }

        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += numTreesHelp(i, buf) * numTreesHelp(n - 1 - i, buf);
        }

        buf[n] = sum;
        return sum;
    }

    int numTrees(int n)
    {
        int *buf = new int[n+1];
        for (int i = 0; i < (n+1); ++i)
        {
            buf[i] = 0;
        }

        int len = numTreesHelp(n, buf);

        delete []buf;

        return len;
    }
};

int main()
{
    Solution s;

    cout << s.numTrees(3) << endl;

    return 0;
}
