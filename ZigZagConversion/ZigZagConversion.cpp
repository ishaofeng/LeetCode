#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cctype>
#include <cmath>

using namespace std;


class Solution
{
public:
    string convert(string text, int nRows)
    {
        if (nRows <= 1)
        {
            return text;
        }
        string result;
        int special = nRows / 2 - 1;
        int sec = nRows * 2 - 2;
        for (int i = 0; i < nRows; ++i)
        {
            for (int j = i; j < text.size();)
            {
                result.push_back(text[j]);


                int sp = j / sec;
                int mod = j % sec;

                if (mod < (nRows-1) && mod > 0)
                {
                    sp = (sp + 1) * sec - mod;
                    if (sp < text.size())
                    {
                        result.push_back(text[sp]);
                    }
                }

                j += sec;
            }
        }

        return result;
    }
};

int main()
{
    int data[] = { 2, 3, 4, 5, 6, 1};
    vector<int> v(data, data + sizeof(data) / sizeof(data[0]));
    Solution s;
    string ss = "PAYPALISHIRING";
    string result = s.convert(ss, 4);
    cout << "#" << result << "#" << endl;
}
