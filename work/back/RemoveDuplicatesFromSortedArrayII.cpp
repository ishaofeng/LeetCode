#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(int A[], int n)
    {
        if (A == NULL || n <= 0)
        {
            return n;
        }

        int index = 1;
        int last = A[0];
        int bFirst = true;
        for (int i = 1; i < n; ++i)
        {
            if (A[i] != last)
            {
                A[index++] = A[i];
                bFirst = true;
            }
            else
            {
                //前面相同值只出现过一次
                if (bFirst)
                {
                    bFirst = false;
                    A[index++] = A[i];
                }
            }
            last = A[i];
        }

        return index;
    }
};

int main()
{
    int A[] = {1, 1, 1, 2, 2, 2, 3, 4, 4};
    Solution s;
    int len = s.removeDuplicates(A, sizeof(A) / sizeof(A[0]));
    for (int i = 0; i < len; ++i)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
