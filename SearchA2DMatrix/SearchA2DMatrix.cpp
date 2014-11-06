#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target)
    {
        int row = matrix.size();
        int column = matrix[0].size();
        if (row < 1 || column < 1)
        {
            return false;
        }

        int i = 0;
        for (; i < row; ++i)
        {
            if (matrix[i][column-1] >= target)
            {
                int start = 0, end = column - 1, mid, value;
                while (start <= end)
                {
                    mid = (start + end) >> 1;
                    value = matrix[i][mid];
                    if (value == target)
                    {
                        return true;
                    }
                    else if (value < target)
                    {
                        start = mid + 1;
                    }
                    else
                    {
                        end = mid - 1;
                    }
                }
            }
        }

        return false;
    }
};

int main()
{
    vector<vector<int> > matrix;
    vector<int> m1;
    m1.push_back(1);
    m1.push_back(3);
    matrix.push_back(m1);

    vector<int> m2;
    m2.push_back(10);
    m2.push_back(11);
    m2.push_back(16);
    m2.push_back(20);
    //matrix.push_back(m2);

    vector<int> m3;
    m3.push_back(23);
    m3.push_back(30);
    m3.push_back(34);
    m3.push_back(50);
    //matrix.push_back(m3);

    Solution s;
    cout << "result: " << s.searchMatrix(matrix, 3) << endl;
}
