#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

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

void printv(vector<int> &v)
{
    int len = v.size();
    cout << "======================" << endl;
    for (int i = 0; i < len; ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
void printV(vector<vector<int> > &vec)
{
    int row = vec.size();
    int column = vec[0].size();

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            cout << vec[i][j] << "  ";
        }
        cout << endl;
    }
}

class Solution
{
public:
    int trap(int A[], int n)
    {
        if (A == NULL || n <= 2)
        {
            return 0;
        }

        int trap = 0;
        int start = -1;
        for (int i = 0; i < n; ++i)
        {
            if (A[i] != 0)
            {
                start = i;
                break;
            }
        }
        if (start == -1)
        {
            return 0;
        }

        int j, max, maxi;
        for (int i = start; i < n; )
        {
            max = 0;
            for (j = i + 1; j < n; ++j)
            {
                if (A[j] >= max)
                {
                    max = A[j];
                    maxi = j;
                }

                if (max >= A[i])
                {
                    max = A[i];
                    maxi =j;
                    break;
                }

            }

            for (int k = i + 1; k < maxi; ++k)
            {
                if (max > A[k])
                {
                    trap += max - A[k];
                }
            }

            i = maxi;
            if (i == (n - 1))
            {
                break;
            }
        }

        return trap;
    }
};

int main()
{
    int data[][3] = {{1, 2, 3},
                    {12, 13, 4},
                    {11, 14, 5},
                    {10, 15, 6},
                    {9, 8, 7}};
    vector<vector<int> > v;
    for (int i = 0; i < 5; ++i)
    {
        vector<int> row(data[i], data[i] + 3);
//        v.push_back(row);
    }
    cout << "start" << endl;
    int A[] = {4, 2, 3};
    Solution s;
    cout << s.trap(A, sizeof(A) / sizeof(A[0]));
}
