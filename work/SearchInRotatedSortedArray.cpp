#include <iostream>

using namespace std;

class Solution
{
public:
    bool search(int A[], int n, int target)
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
            while ((start+1) <= end && A[start] == A[start+1])
            {
                ++start;
            }
            while (start <= (end-1) && A[end] == A[end-1])
            {
                --end;
            }

            mid = (start + end) >> 1;
            if (A[mid] == target)
            {
                return true;
            }
            else if (A[start] < A[end] && target < A[mid] || target > A[end] && (A[mid] < A[end] || target < A[mid]) ||  target < A[mid] && A[mid] <= A[end])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return false;
    }
};

int main()
{
//    int A[] = {5, 1, 2, 3, 4};
//    int A[] = {4, 4, 5, 5, 5, 6, 7, 0, 1, 2};
    int A[] = {1, 1, 3, 1};
    Solution s;
    int len = sizeof(A) / sizeof(A[0]);
    for (int i = 0; i < len; ++i)
    {
        cout << "find result: " << s.search(A, len, A[i]) << endl;
    }

    return 0;
}
