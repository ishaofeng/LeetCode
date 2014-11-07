#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void merge(int A[], int m, int B[], int n)
    {
        if (A == NULL || B == NULL)
        {
            return ;
        }

        int aend = m - 1;
        int bend = n - 1;

        int iend = m + n - 1;

        while (bend >= 0)
        {
            while (bend >= 0 && (aend < 0 || A[aend] < B[bend]))
            {
                A[iend--] = B[bend--];
            }
            A[iend--] = A[aend--];
        }
    }

    void print(int A[], int n)
    {
        cout << endl;
        for (int i = 0; i < n; ++i)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


int main()
{
    int data[40] = {};
    int data1[] = {1};

    int len1 = 0;
    int len2 = sizeof(data1) / sizeof(data1[0]);
    Solution s;
    s.merge(data, len1, data1, len2);
    s.print(data, len1 + len2);

    return 0;
}
