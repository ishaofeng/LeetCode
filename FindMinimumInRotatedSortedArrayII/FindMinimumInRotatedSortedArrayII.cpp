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
        while (beg < end)
        {
            while (beg < end && (num[beg] == num[beg+1] || num[beg] == num[end]))
            {
                ++beg;
            }
            mid = beg + ((end - beg) > 1);
            if (beg == end)
            {
                break;
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

        return num[beg];
    }
};

int main()
{
    int data[] = { 2, 2, 3, 4, 5, 6, 1, 1, 1};
    vector<int> v(data, data + sizeof(data) / sizeof(data[0]));
    Solution s;
    cout << s.findMin(v) << endl;
}
