#include <iostream>
#include <vector>
#include <set>
#include <cctype>
#include <map>
#include <unordered_map>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <limits>
#include <algorithm>
#include <list>
#include <utility>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        int len = s.length();
        if (len & 0x01 == 1)
        {
            return false;
        }

        stack<char> ss;
        for (int i = 0; i < len; ++i)
        {
            if (s[i] == ')' || s[i] == ']' || s[i] == '}')
            {
                if (ss.empty())
                {
                    return false;
                }
                else
                {
                    if (ss.top() == '(' && s[i] == ')' ||
                        ss.top() == '[' && s[i] == ']' ||
                        ss.top() == '{' && s[i] == '}')
                    {
                        ss.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            else
            {
                ss.push(s[i]);
            }
        }
        return ss.empty();
    }
};

int main()
{
    Solution s;
    cout << s.isValid("") << endl;
}
