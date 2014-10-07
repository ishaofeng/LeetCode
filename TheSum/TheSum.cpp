#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int> &numbers, int target)
        {
            vector<int> result;

            vector<int> sortnumbers = numbers;
            sort(sortnumbers.begin(), sortnumbers.end());

            int beg = 0;
            int end = numbers.size() - 1;

            int sum;
            while (beg < end)
            {
                sum = sortnumbers[end] + sortnumbers[beg];
                if (sum == target)
                {
                    break;
                }
                else if (sum > target)
                {
                    --end;
                }
                else
                {
                    ++beg;
                }
            }

            int i1, i2;
            for (int i = 0; i < numbers.size(); ++i)
            {
                if (sortnumbers[beg] == numbers[i])
                {
                    i1 = i;
                    break;
                }
            }

            for (int i = 0; i < numbers.size(); ++i)
            {
                if (sortnumbers[end] == numbers[i] && i != i1)
                {
                    if (i < i1)
                    {
                        i2 = i1;
                        i1 = i;
                    }
                    else
                    {
                        i2 = i;
                    }
                    break;
                }
            }

            ++i1;
            ++i2;

            result.push_back(i1);
            result.push_back(i2);

            return result;
        }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> numbers;
    numbers.push_back(7);
    numbers.push_back(75);
    numbers.push_back(25);
    vector<int> v = s.twoSum(numbers, 100);

    if (v.size() > 0)
    {
        cout << "index1: " << v[0] << "   index2:" << v[1] << endl;
    }
    else
    {
        cout << "No Answer" << endl;
    }

    return 0;
}
