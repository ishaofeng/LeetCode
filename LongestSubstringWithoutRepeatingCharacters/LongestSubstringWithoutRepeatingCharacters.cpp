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
    int lengthOfLongestSubstring(string s)
    {
        int m[256] = {0};

        int beg = 0, cur = 0;
        int longest = 0;
        int c;
        while (cur < s.size())
        {
            c = m[s[cur]];
            if (c > 0)
            {
                if ((cur - beg) > longest)
                {
                    longest = cur - beg;
                }
                for (int i = beg; i < (c-1); ++i)
                {
                    m[s[i]] = 0;
                }
                m[s[cur]] = cur + 1;
                beg = c;
            }
            else
            {
                m[s[cur]] = cur + 1;
            }
            ++cur;
        }
        if ((cur - beg) > longest)
        {
            longest = cur - beg;
        }

        return longest;
    }
};

int main()
{
    Solution s;
//    string ss = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
    string ss = "qopubjguxhxdipfzwswybgfylqvjzhar";
    cout << s.lengthOfLongestSubstring(ss) << endl;
}
