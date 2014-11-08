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
    vector<vector<int> > generateMatrix(int n)
    {
        vector<vector<int> > result;
        if (n <= 0)
        {
            return result;
        }

        for (int i = 0; i < n; ++i)
        {
            vector<int> line(n);
            result.push_back(line);
        }

        //所要处理的圈数
        int height = n;
        height = height / 2 + ((height % 2 == 0) ? 0 : 1);

        int row = n;
        int column = n;

        int count = n * n;
        int c = 1;

        int left = 0, right = column - 1, top = 0, bottom = row - 1;
        int i, j;
        for (int k = 0; k < height; ++k)
        {
            i = k;
            j = k;
            for (; j <= right; ++j)
            {
                result[i][j] = c;
                ++c;
            }
            if (result.size() == count)
            {
                break;
            }

            ++i;
            --j;
            for (; i <= bottom; ++i)
            {
                result[i][j] = c;
                ++c;
            }
            if (result.size() == count)
            {
                break;
            }

            --j;
            --i;
            for (; j >= left; --j)
            {
                result[i][j] = c;
                ++c;
            }
            if (result.size() == count)
            {
                break;
            }

            --i;
            ++j;
            for (; i > top; --i)
            {
                result[i][j] = c;
                ++c;
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
    vector<vector<int> > result = s.generateMatrix(4);
    printV(result);
}
