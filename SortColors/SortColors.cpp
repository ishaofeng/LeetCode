#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(int A[], int len)
{
    cout << "======================" << endl;
    for (int i = 0; i < len; ++i)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

class Solution
{
public:
    void sortColors(int A[], int n)
    {
        if (A == NULL || n <= 0)
        {
            return ;
        }

        int red = -1, blue = n;
        int index = 0;
        int tag;
        while (index < blue)
        {
            if (A[index] == 0)
            {
                ++red;
                if (red != index)
                {
                    swap(A[red], A[index]);
                }

                ++index;
            }
            else if (A[index] == 2)
            {
                --blue;
                if (blue != index)
                {
                    swap(A[blue], A[index]);
                }
            }
            else
            {
                ++index;
            }
        }
    }

    void swap(int &a, int &b)
    {
        a ^= b;
        b ^= a;
        a ^= b;
    }
};

int main()
{
    int A[] = {1, 2, 0, 0, 1, 1, 2, 0};
    int len = sizeof(A) / sizeof(A[0]);
    Solution s;
    s.sortColors(A, len);

    print(A, len);
}
