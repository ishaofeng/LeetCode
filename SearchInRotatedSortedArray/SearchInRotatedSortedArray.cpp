#include <iostream>

using namespace std;

class Solution
{
public:
    int search(int A[], int n, int target)
    {
        if (NULL == A)
        {
            return -1;
        }

        int start = 0;
        int end = n - 1;
        int mid;

        while (start <= end)
        {
            cout << start << "  " << end << endl;
            mid = (start + end) >> 1;
            if (A[mid] == target)
            {
                return mid;
            }
            else if (A[start] < A[end] && target < A[mid] || target > A[end] && (A[mid] < A[end] || target < A[mid]) ||  target < A[mid] && A[mid] < A[end])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return -1;
    }
};

int main()
{
//    int A[] = {5, 1, 2, 3, 4};
    int A[] = {4, 5, 6, 7, 0, 1, 2};
    Solution s;
    for (int i = 0; i < 5; ++i)
    {
        cout << "find result: " << s.search(A, 5, A[i]) << endl;
    }

    return 0;
}
