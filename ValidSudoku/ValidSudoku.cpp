#include <iostream>
#include <vector>
#include <set>
#include <cctype>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
        int row = board.size();
        if (row <= 0)
        {
            return true;
        }
        int column = board[0].size();
        if (column <= 0)
        {
            return true;
        }


        int n = 0;
        char c;
        //同一行不存在相同的数
        for (int i = 0; i < row; ++i)
        {
            n = 0;
            for (int j = 0; j < column; ++j)
            {
                c = board[i][j];
                if (c == '.')
                {
                    continue;
                }

                if (n & (1 << c))
                {
                    return false;
                }
                else
                {
                    n |= (1 << c);
                }
            }
        }
        cout << "1" << endl;
        //同一列不存在相同的数
        for (int i = 0; i < column; ++i)
        {
            n = 0;
            for (int j = 0; j < row; ++j)
            {
                c = board[j][i];
                if (c == '.')
                {
                    continue;
                }

                if (n & (1 << c))
                {
                    return false;
                }
                else
                {
                    n |= (1 << c);
                }
            }
        }
        cout << "2" << endl;

        //同一个9个格子的块
        row -= 2;
        column -= 2;
        for (int i = 0; i < row; i += 3)
        {
            for (int j = 0; j < column; j += 3)
            {
                n = 0;
                for (int ii = 0; ii < 3; ++ii)
                {
                    for (int jj = 0; jj < 3; ++jj)
                    {
                        c = board[i + ii][j + jj];
                        if (c == '.')
                        {
                            continue;
                        }

                        if (n & (1 << c))
                        {
                            cout << i << " " << j << endl;
                            return false;
                        }
                        else
                        {
                            n |= (1 << c);
                        }
                    }
                }
            }
        }

        return true;
    }
};

int main()
{
    Solution s;
//    const char *data[9] = {"..5.....6","....14...",".........",".....92..","5....2...",".......3.","...54....","3.....42.","...27.6.."};
    const char *data[9] = {"..4...63.",".........","5......9.","...56....","4.3.....1","...7.....","...5.....",".........","........."};
    vector<vector<char> > board;
    for (int i = 0; i < 9; ++i)
    {
        cout << data[i] << endl;
        vector<char> line;
        for (int j = 0; j < 9; ++j)
        {
            line.push_back(data[i][j]);
        }
        board.push_back(line);
    }
    cout << endl;
    cout << s.isValidSudoku(board) << endl;

}
