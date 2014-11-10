#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cctype>

using namespace std;


class Solution
{
public:
    int findMin(vector<int> &num)
    {
        if (num.empty())
        {
            return -1;
        }

        int beg = 0, end = num.size() - 1, mid;
        while (beg <= end)
        {
            mid = beg + ((end - beg) > 1);
            if (num[mid] == num[end] && num[end] == num[beg])
            {
                return num[end];
            }
            else if (num[beg] < num[end])
            {
                return num[beg];
            }
            else if (num[beg] > num[end] && num[mid] >= num[beg])
            {
                beg = mid + 1;
            }
            else
            {
                end = mid;
            }
        }
    }
};

int main()
{
    int data[] = { 2, 3, 4, 5, 6, 1};
    vector<int> v(data, data + sizeof(data) / sizeof(data[0]));
    Solution s;
    cout << s.findMin(v) << endl;
}
