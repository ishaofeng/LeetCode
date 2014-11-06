#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void printV(vector<int> &num)
    {
        int row = num.size();
        for (int i = 0; i < row; ++i)
        {
            cout << num[i] << " ";
        }
        cout << endl;
    }
    void nextPermutation(vector<int> &num)
    {
        int len = num.size();
        int lastIndex = -1;
        for (int i = len - 2; i >= 0; --i)
        {
            if (num[i] < num[i+1])
            {
                lastIndex = i;
                break;
            }
        }
        reverse(num, lastIndex);
        if (lastIndex == -1)
        {
            return ;
        }

        for (int i = lastIndex + 1; i < len; ++i)
        {
            if (num[i] > num[lastIndex])
            {
                swap(num[i], num[lastIndex]);
                break;
            }
        }
    }

    void swap(int &a, int &b)
    {
        a ^= b;
        b ^= a;
        a ^= b;
    }

    int reverse(vector<int> &num, int lastIndex)
    {
        int len = num.size();

        int start = lastIndex + 1;
        int end = len - 1;
        while (start < end)
        {
            swap(num[start], num[end]);

            ++start;
            --end;
        }
    }
};


int main()
{
    int data[] = {4, 2, 3, 1};
    vector<int> num(data, data + sizeof(data) / sizeof(data[0]));

    Solution s;
    s.nextPermutation(num);
    s.printV(num);

    return 0;
}
