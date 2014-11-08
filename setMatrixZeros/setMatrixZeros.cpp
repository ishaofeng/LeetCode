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
    void setZeroes(vector<vector<int> > &matrix)
    {
        int row = matrix.size();
        int column = matrix[0].size();


        //统计响应行或者列存在0的项
        set<int> srow;
        set<int> scolumn;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < column; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    cout << i << " " << j << " " << matrix[i][j] << endl;
                    srow.insert(i);
                    scolumn.insert(j);
                }
            }
        }

        //将统计的行和列置0
        set<int>::iterator it = srow.begin();
        for (; it != srow.end(); ++it)
        {
            cout << "row: " << *it << endl;
            for (int i = 0; i < column; ++i)
            {
                matrix[*it][i] = 0;
            }
        }
        for (it = scolumn.begin(); it != scolumn.end(); ++it)
        {
            cout << "column: " << *it << endl;
            for (int i = 0; i < row; ++i)
            {
                matrix[i][*it] = 0;
            }
        }
        cout << "end" << endl;
    }

    void swap(int &a, int &b)
    {
        a ^= b;
        b ^= a;
        a ^= b;
    }
};

int main()
{
    /*
    int data[][3] = {{2147483647, 2, 9},
                                {2, 6, 7},
                                {1, 8, 8},
                                {5, 0, 1},
                                {9, 6, 0}};
    */
    int data[][2] = {{0, 1}};
    vector<vector<int> > vec;
    for (int i = 0; i < 1; ++i)
    {
        vector<int> a(data[i], data[i] + 2);
        vec.push_back(a);
    }

    printV(vec);
    Solution s;
    s.setZeroes(vec);
    printV(vec);
}
