#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeElement(int A[], int n, int elem)
    {
        if (A == NULL || n <= 0)
        {
            return n;
        }

        int i = 0, index = -1;
        for (; i < n; ++i)
        {
            if (A[i] != elem)
            {
                ++index;
                if (i != index)
                {
                    A[index] = A[i];
                }
            }
        }

        return index + 1;
    }
};

int main()
{
    int A[] = {1, 2, 3, 3, 2, 3, 2, 1};
    Solution s;
    cout << "result: " << s.removeElement(A, sizeof(A) / sizeof(A[0]), 1) << endl;

    return 0;
}
