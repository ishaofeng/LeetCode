#include <iostream>
#include <vector>
#include <set>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <algorithm>
using namespace std;


struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
class Solution
{
public:
    int maxSubArray(int A[], int n)
    {
        if (A == NULL || n <= 0)
        {
            return 0;
        }

        int maxval = -(numeric_limits<int>::max)();
        bool bSet = false;
        int continuevalue = 0;
        for (int i = 0; i < n; ++i)
        {
            continuevalue += A[i];
            if (continuevalue > maxval)
            {
                maxval = continuevalue;
            }
            if (continuevalue < 0)
            {
                bSet = false;
                continuevalue = 0;
            }
        }

        return maxval;
    }
};

int main()
{
    int data[] = { 2, 3, 4, 5, 6, 1};
    vector<int> v(data, data + sizeof(data) / sizeof(data[0]));
    Solution s;
    string ss = "PAYPALISHIRING";
    int data1[][3] = {{1, 0, 0},
                      {0, 1, 0},
                      {2, 0, 3}};
    vector<vector<int> > vv;
    for (int i = 0; i < 3; ++i)
    {
        vector<int> line;
        for (int j = 0; j < 3; ++j)
        {
            line.push_back(data1[i][j]);
        }
        vv.push_back(line);
    }
    vector<Interval> intervals;
    intervals.push_back(Interval(1, 3));
    intervals.push_back(Interval(2, 6));
    intervals.push_back(Interval(8, 10));
    intervals.push_back(Interval(15, 18));

    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << s.maxSubArray(A, sizeof(A) / sizeof(A[0]));
}
