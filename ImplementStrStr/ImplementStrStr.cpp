#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string.h>
#include <iterator>
using namespace std;

struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution
{
public:
    void getNext(const char *p, int next[])
    {
        int len = strlen(p);
        next[0] = -1;

        int k = -1;
        int i = 0;
        while (i < (len -1))
        {
            if (k == -1 || p[i] == p[k])
            {
                ++k;
                ++i;
                if (p[i] != p[k])
                {
                    next[i] = k;
                }
                else
                {
                    next[i] = next[k];
                }
                copy(next, next + len, ostream_iterator<int>(cout, " "));
                cout << endl;
            }
            else
            {
                k = next[k];
            }
        }
    }
    int strStr(const char *str, const char *p)
    {
        int sl = strlen(str);
        int pl = strlen(p);
        int i = 0;
        int j = 0;

        int *next = new int[pl];
        memset(next, 0, sizeof(int) * pl);
        getNext(p, next);

        while (i < sl && j < pl)
        {
            if (j == -1 || str[i] == p[j])
            {
                ++i;
                ++j;
            }
            else
            {
                j = next[j];
            }
        }
        delete [] next;

        if (j == pl)
        {
            return i - j;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    Solution s;
    s.strStr("", "abab");
}
