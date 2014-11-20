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
    string simplifyPath(string path)
    {

        vector<string> s;
        string item;
        for (int i = 1; i < path.size(); ++i)
        {
            if (path[i] == '/' || i == (path.size() -1))
            {
                if (path[i] != '/')
                {
                    item += path[i];
                }
                if (item == "..")
                {
                    if (!s.empty())
                    {
                        s.pop_back();
                    }
                }
                else if (item != "." && item != "")
                {
                    s.push_back(item);
                }
                item = "";
            }
            else
            {
                item += path[i];
            }
        }

        string p = "";
        for (int i = 0; i < s.size(); ++i)
        {
            p += "/" + s[i];
        }
        if (p.empty())
        {
            p = "/";
        }

        return p;
    }
};

int main()
{
    Solution s;
    cout << s.simplifyPath("/...") << endl;
}
