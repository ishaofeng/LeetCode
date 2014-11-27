#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0)
        {
            return "";
        }
        if (strs.size() == 1)
        {
            return strs[0];
        }
        int len = numeric_limits<int>::max();
        for_each(strs.begin(), strs.end(), [&len] (const string &s) { if (s.length() < len) len = s.length(); });

        string prefix;
        char a;
        for (int i = 0; i < len; ++i)
        {
            a = strs[0][i];
            int j = 1;
            for (; j < strs.size(); ++j)
            {
                if (a != strs[j][i])
                {
                    break;
                }
            }
            if (j == strs.size())
            {
                prefix.append(1, a);
            }
            else
            {
                return prefix;
            }
        }
        return prefix;
    }
};

int main()
{
    Solution s;
    vector<string> strs{"aaaa", "aaa"};
    cout << s.longestCommonPrefix(strs) << endl;
}
