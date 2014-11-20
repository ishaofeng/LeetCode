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
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    bool anagram(string &s)
    {
        int beg = 0;
        int end = s.length() - 1;
        while (beg < end)
        {
            if (s[beg++] != s[end--])
            {
                return false;
            }
        }

        return true;
    }
    vector<string> anagrams(vector<string> &strs)
    {
        vector<string> result;

        string tmp;
        multiset<string> s;
        for (int i = 0; i < strs.size(); ++i)
        {
            tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            s.insert(tmp);
        }

        string rev;
        int c;
        for (int i = 0; i < strs.size(); ++i)
        {
            tmp = strs[i];
            sort(tmp.begin(), tmp.end());

            c = s.count(tmp);
            if (c >= 2)
            {
                result.push_back(strs[i]);
            }
        }

        return result;
    }
};

int main()
{
    vector<string> strs;
    strs.push_back("abc");
    strs.push_back("cba");
    strs.push_back("aba");
    strs.push_back("ant");
    strs.push_back("ant");
    Solution s;
    vector<string> v =  s.anagrams(strs);
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
