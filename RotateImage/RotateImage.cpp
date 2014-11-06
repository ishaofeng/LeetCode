#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int> > &matrix)
    {
        int n = matrix.size();
        int height = n / 2;
        --n;

        int end, value, keepvalue;
        for (int i = 0; i < height; ++i)
        {
            end = n - i;
            for (int j = i; j < end; ++j)
            {
                value = matrix[j][n-i];
                matrix[j][n-i] = matrix[i][j];

                keepvalue = matrix[n-i][n-j];
                matrix[n-i][n-j] = value;
                value = keepvalue;

                keepvalue = matrix[n-j][i];
                matrix[n-j][i] = value;

                matrix[i][j] = keepvalue;
            }
        }
    }
};

int main()
{
    vector<vector<int> > matrix;
    vector<int> m1;
    m1.push_back(1);
    m1.push_back(3);
  //  m1.push_back(4);
    matrix.push_back(m1);

    vector<int> m2;
    m2.push_back(10);
    m2.push_back(11);
 //   m2.push_back(16);
    matrix.push_back(m2);

    vector<int> m3;
    m3.push_back(23);
    m3.push_back(30);
    m3.push_back(34);
//    matrix.push_back(m3);

    Solution s;
    s.rotate(matrix);
    int n = matrix.size();

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
