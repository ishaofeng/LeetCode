#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        ++rowIndex;

        vector<int> line;
        if (rowIndex <= 0)
        {
            return line;
        }

        line.push_back(1);

        vector<int> lastline = line;
        for (int i = 1; i < rowIndex; ++i)
        {
            line.clear();

            line.push_back(1);
            for (int j = 1; j < i; ++j)
            {
                line.push_back(lastline[j-1] + lastline[j]);
            }
            line.push_back(1);

            lastline = line;
        }

        return line;
    }
};

int main()
{
    Solution s;
    vector<int> result = s.getRow(3);
    int row = result.size();
    for (int i = 0; i < row; ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
