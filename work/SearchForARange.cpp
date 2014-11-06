#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(int A[], int n, int target)
    {
        vector<int> result;
        if (A == NULL || n <= 0)
        {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }

        int start = 0, end = n - 1, mid;

        while (start <= end)
        {
            mid = (start + end) >> 1;
            if (A[mid] == target)
            {
                while (mid >= 0 && A[mid] == target)
                {
                    --mid;
                }
                ++mid;
                result.push_back(mid);
                while (mid < n && A[mid] == target)
                {
                    ++mid;
                }
                --mid;
                result.push_back(mid);

                return result;
            }
            else if (A[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        result.push_back(-1);
        result.push_back(-1);
        return result;
    }
};

int main()
{
    int A[] = {5, 7, 7, 8, 8, 10};

    Solution s;
    vector<int> result = s.searchRange(A, sizeof(A) / sizeof(A[0]), 7);
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
