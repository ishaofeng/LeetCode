#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int> > subsets(vector<int> &s)
    {
        vector<vector<int> > result = {{}};

        sort(s.begin(), s.end());

        for (int i = 0; i < s.size();)
        {
            int count = 0;
            while (count + i < s.size() && s[i] == s[count+i])
            {
                ++count;
            }

            int resultsize = result.size();
            for (int j = 0; j < resultsize; ++j)
            {
                vector<int> line = result[j];
                for (int k = 0; k < count; ++k)
                {
                    line.push_back(s[i]);
                    result.push_back(line);
                }
            }

            i += count;
        }

        return result;
    }

    void print(vector<vector<int> > &data)
    {
        int row = data.size();
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < data[i].size(); ++j)
            {
                cout << data[i][j] << " ";
            }

            cout << endl;
        }
    }
};


int main()
{
    int data[] = {1, 2, 2, 2};

    vector<int> v(data, data + sizeof(data) / sizeof(data[0]));
    Solution s;
    vector<vector<int> > result = s.subsets(v);
    cout << result.size() << endl;
    s.print(result);

    return 0;
}
