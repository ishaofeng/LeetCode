#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void print(int A[], int len)
{
    cout << "======================" << endl;
    for (int i = 0; i < len; ++i)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void printv(vector<int> &v)
{
    int len = v.size();
    cout << "======================" << endl;
    for (int i = 0; i < len; ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
void printV(vector<vector<int> > &vec)
{
    int row = vec.size();
    int column = vec[0].size();

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            cout << vec[i][j] << "  ";
        }
        cout << endl;
    }
}

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix)
    {
        vector<int> result;
        int row = matrix.size();
        if (row <= 0)
        {
            return result;
        }

        int column = matrix[0].size();
        if (column <= 0)
        {
            return result;
        }

        //所要处理的圈数
        int height = min(row, column);
        height = height / 2 + ((height % 2 == 0) ? 0 : 1);

        int count = row * column;
        int left = 0, right = column - 1, top = 0, bottom = row - 1;
        int i, j;
        for (int k = 0; k < height; ++k)
        {
            i = k;
            j = k;
            for (; j <= right; ++j)
            {
                result.push_back(matrix[i][j]);
            }

            if (result.size() == count)
            {
                break;
            }

            ++i;
            --j;
            for (; i <= bottom; ++i)
            {
                result.push_back(matrix[i][j]);
            }
            if (result.size() == count)
            {
                break;
            }

            --j;
            --i;
            for (; j >= left; --j)
            {
                result.push_back(matrix[i][j]);
            }
            if (result.size() == count)
            {
                break;
            }

            --i;
            ++j;
            for (; i > top; --i)
            {
                result.push_back(matrix[i][j]);
            }

            ++left;
            ++top;
            --right;
            --bottom;
        }

        return result;
    }
};

int main()
{
    int data[][3] = {{1, 2, 3},
                    {12, 13, 4},
                    {11, 14, 5},
                    {10, 15, 6},
                    {9, 8, 7}};
    vector<vector<int> > v;
    for (int i = 0; i < 5; ++i)
    {
        vector<int> row(data[i], data[i] + 3);
//        v.push_back(row);
    }
    cout << "start" << endl;
    int A[] = {1, 3, 5, 6};
    Solution s;
    vector<int> result = s.spiralOrder(v);
    printv(result);
}
