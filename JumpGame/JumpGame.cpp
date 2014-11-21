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
using namespace std;

//自己写的算法复杂度为o(n*2) canJump 使用了动态规划
//提交通过的算法是看别人的, 是贪心实现, 一直更新自己最远能到达的
class Solution
{
public:
    bool canJump(int A[], int n)
    {
        if (A == NULL || n <= 0)
        {
            return true;
        }

        vector<int> keep(n, -1);

        int end = n - 1;
        int lastok = -1;
        for (int i = n - 2; i >= 0; --i)
        {
            for (int j = 1; j <= A[i]; ++j)
            {
                if (i + j == end || keep[i+j] == 1)
                {
                    keep[i] = 1;
                    break;
                }
            }
            if (keep[i] == -1)
            {
                keep[i] = 0;
            }
        }
        for (int i = 0; i < keep.size(); ++i)
        {
            cout << keep[i] << " ";
        }
        cout << endl;

        return keep[0];
    }

    bool canJump1(int A[], int n)
    {
        int canreach = 0;
        int i = 0;
        for (; i < n && i <= canreach; ++i)
        {
            canreach = max(i + A[i], canreach);
        }

        return i == n;
    }
};

int main()
{
    Solution s;

    int A[] = {3, 2, 1, 0, 4};
    cout << s.canJump1(A, sizeof(A) / sizeof(A[0])) << endl;
}
