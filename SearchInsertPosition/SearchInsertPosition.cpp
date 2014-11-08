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
    int searchInsert(int A[], int n, int target)
    {
        if (A == NULL || n <= 0)
        {
            return 0;
        }

        int left = 0, right = n - 1, mid;
        while (left < right)
        {
            mid = left + ((right - left) >> 1);
            if (A[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        if (A[left] == target)
        {
            return left;
        }
        else if (A[left] < target)
        {
            return left + 1;
        }
        else
        {
            return left;
        }
    }
};

int main()
{
    /*
    int data[][3] = {{2147483647, 2, 9},
                                {2, 6, 7},
                                {1, 8, 8},
                                {5, 0, 1},
                                {9, 6, 0}};
    */
    int A[] = {1, 3, 5, 6};
    Solution s;
    cout << s.searchInsert(A, 4, 0) << endl;
}
