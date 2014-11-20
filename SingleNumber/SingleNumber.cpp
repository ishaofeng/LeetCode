#include <iostream>
#include <vector>
#include <set>
#include <cctype>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int singleNumber(int A[], int n)
    {
        int test = A[0];
        for (int i = 1; i < n; ++i)
        {
            test ^= A[i];
        }

        return test;
    }
};

int main()
{
    Solution s;
    int A[] = {6, 2, 7, 6, 2, 9, 7};
    cout << s.singleNumber(A, sizeof(A)/ sizeof(A[0]));
}
