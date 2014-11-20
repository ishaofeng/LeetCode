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
    string minWindow(string S, string T)
    {
        string result;

        int chars[256] = {0};
        int counts[256] = {0};

        for (int i = 0; i < T.length(); ++i)
        {
            chars[T[i]] += 1;
        }

        int beg = 0, end = 0, cur = 0;
        int lastbeg = -1, lastend = -1;
        int count = 0;
        while (cur < S.length())
        {
            if (count == 0 && beg >= end && chars[S[cur]] == 0)
            {
                ++beg;
                ++end;
            }
            else if (counts[S[cur]] < chars[S[cur]])
            {
                ++counts[S[cur]];
                ++count;
                end = cur;
            }
            else
            {
                //当前元素为目标元素
                if (chars[S[cur]] != 0)
                {
                    if (count == T.size() && (lastbeg == -1 || (end - beg) < (lastend - lastbeg)))
                    {
                        lastbeg = beg;
                        lastend = end;
                    }

                    while (S[beg] != S[cur])
                    {
                        if (chars[S[beg]] > 0)
                        {
                            --counts[S[beg]];
                            --count;
                        }
                        ++beg;
                    }
                    ++beg;
                    while (chars[S[beg]] == 0)
                    {
                        ++beg;
                    }
                    end = cur;
                }

            }
            ++cur;
        }

        if (count == T.size())
        {
            if (lastbeg == -1 || (end - beg) <= (lastend - lastbeg))
            {
                lastbeg = beg;
                lastend = end;
            }
        }
        if (lastbeg != -1)
        {
            result = S.substr(lastbeg, lastend - lastbeg + 1);
        }

        return result;
    }
};

int main()
{
    Solution s;

    string S = "ADOBECODEBANC";
    string T = "ABC";

    cout << s.minWindow(S, T) << endl;

    return 0;
}
