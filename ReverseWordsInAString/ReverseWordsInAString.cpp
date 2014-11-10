#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cctype>

using namespace std;


class Solution
{
public:
    void reverseWords(string &s)
    {
        if (s.empty())
        {
            return ;
        }

        //去除空格
        int l = 0, lastspace = -1;
        for (int i = 0; i < s.size(); ++i)
        {
            if (!isspace(s[i]))
            {
                s[l++] = s[i];
            }
            else if ((i+1) < s.size() && !isspace(s[i+1]) && l != 0)
            {
                s[l++] = s[i];
            }
        }

        int len = l;
        l = 0;
        for (int i = 0; i < len; ++i)
        {
            if (isspace(s[i]))
            {
                if (l < i)
                {
                    reverseWordsHelp(s, l, i - 1);
                }
                l = i + 1;

            }
        }
        if (l < s.size())
        {
            reverseWordsHelp(s, l, len - 1);
        }

        reverseWordsHelp(s, 0, len - 1);

        s = s.substr(0, len);
    }

    void reverseWordsHelp(string &s, int l, int r)
    {
        while (l < r)
        {
            swap(s[l], s[r]);
            ++l;
            --r;
        }
    }

    void swap(char &a, char &b)
    {
        a ^= b;
        b ^= a;
        a ^= b;
    }
};

int main()
{
    int data[] = { 2, 3, 4, 5, 6, 1};
    vector<int> v(data, data + sizeof(data) / sizeof(data[0]));
    Solution s;
    string ss = "    t  t  ";
    s.reverseWords(ss);
    cout << "#" << ss << "#" << endl;
}
