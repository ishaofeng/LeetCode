#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char> > &board, string word)
    {
        if (board.size() == 0 || word.size() == 0)
        {
            return false;
        }

        int row = board.size();
        int column = board[0].size();
        bool result = false;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < column; ++j)
            {
                if (board[i][j] == word.at(0))
                {
                    set<int> s;
                    s.insert(i * column + j);
                    if (word.size() == 1)
                    {
                        return true;
                    }
                    result = checkexist(board, i, j, word, 1, s);
                    if (result == true)
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    bool checkexist(vector<vector<char> > &board, int i, int j, string &word, int wi, set<int> &s)
    {
        int row = board.size();
        int column = board[0].size();
        int pos;
        pos = (i-1) * column + j;
        if ((i - 1 >= 0) && s.find(pos) == s.end() && board[i-1][j] == word[wi])
        {
            if (wi + 1 == word.size())
            {
                return true;
            }

            s.insert(pos);
            if (checkexist(board, i - 1, j, word, wi + 1, s))
            {
                return true;
            }
            s.erase(pos);
        }

        pos = i * column + j + 1;
        if ((j + 1 < column) && s.find(pos) == s.end() && board[i][j+1] == word[wi])
        {
            if (wi + 1== word.size())
            {
                return true;
            }

            s.insert(pos);
            if (checkexist(board, i, j+1, word, wi + 1, s))
            {
                return true;
            }
            s.erase(pos);
        }

        pos = (i+1) * column + j;
        if ((i + 1 < row) && s.find(pos) == s.end() && board[i+1][j] == word[wi])
        {
            if (wi + 1 == word.size())
            {
                return true;
            }

            s.insert(pos);
            if (checkexist(board, i + 1, j, word, wi + 1, s))
            {
                return true;
            }
            s.erase(pos);
        }

        pos = i * column + j - 1;
        if ((j - 1 >= 0) && s.find(pos) == s.end() && board[i][j-1] == word[wi])
        {
            if (wi + 1 == word.size())
            {
                return true;
            }

            s.insert(pos);
            if (checkexist(board, i, j-1, word, wi + 1, s))
            {
                return true;
            }
            s.erase(pos);
        }
        return false;
    }
};


int main()
{
    Solution so;
    vector<vector<char> > board;

    vector<char> a1;
    a1.push_back('A');
    a1.push_back('B');
    a1.push_back('C');
    a1.push_back('E');
    board.push_back(a1);

    vector<char> a2;
    a2.push_back('S');
    a2.push_back('F');
    a2.push_back('C');
    a2.push_back('S');
    board.push_back(a2);

    vector<char> a3;
    a3.push_back('A');
    a3.push_back('D');
    a3.push_back('E');
    a3.push_back('E');
    board.push_back(a3);

    cout << "exit: " << so.exist(board, "ABCCED") << endl;;
    cout << "exit: " << so.exist(board, "SEE") << endl;;
    cout << "exit: " << so.exist(board, "ABCB") << endl;;

    return 0;
}

