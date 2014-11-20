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

/*
 * 自己写的一直超时
 * https://oj.leetcode.com/discuss/366/better-solution-than-brute-force
 */

class Solution
{
public:
    //正确提交的
    vector<int> findSubstring1(string S, vector<string> &L)
    {
        vector<int> result;
        if (L.size() < 0 || L[0].size() <= 0)
        {
            return result;
        }

        unordered_map<string, int> words;
        unordered_map<string, int> counts;
        for (int i = 0; i < L.size(); ++i)
        {
            if (words.find(L[i]) != words.end())
            {
                words[L[i]] += 1;
            }
            else
            {
                words[L[i]] = 1;
            }
        }

        int len = L.size();
        int wlen = L[0].size();
        int end = S.size() - wlen + 1;
        int start;
        int count = 0;
        string ts;
        for (int i = 0; i < wlen; ++i)
        {
            start = i;
            count = 0;
            for (int j = i; j < end; j += wlen)
            {
                string s = S.substr(j, wlen);
                if (words.find(s) == words.end() || words[s] == 0)
                {
                    counts.clear();
                    start = j + wlen;
                    count = 0;
                }
                else if (counts[s] < words[s])
                {
                    counts[s] += 1;
                    count += 1;
                }
                else
                {
                    ts = S.substr(start, wlen);
                    while (ts != s)
                    {
                        counts[ts]--;
                        count--;
                        start += wlen;

                        ts = S.substr(start, wlen);
                    }
                    start += wlen;
                }

                if (count == len)
                {
                    result.push_back(start);
                    ts = S.substr(start, wlen);
                    counts[ts]--;
                    count--;
                    start += wlen;
                }
            }
            counts.clear();
        }

        return result;
    }
    vector<int> findSubstring(string S, vector<string> &L)
    {
        vector<int> result;
        if (L.size() < 0 || L[0].size() <= 0)
        {
            return result;
        }

        unordered_map<string, int> words;
        for (int i = 0; i < L.size(); ++i)
        {
            if (words.find(L[i]) != words.end())
            {
                words[L[i]] += 1;
            }
            else
            {
                words[L[i]] = 1;
            }
        }

        int seclen = L[0].size();
        int cur = 0;
        int end = S.size() - seclen * L.size() + 1;
        int i;
        for (; cur < end; ++cur)
        {
            unordered_map<string, int> counts = words;
            for (i = 0; i < L.size(); ++i)
            {
                string t = S.substr(cur + i*seclen, seclen);

                if (counts.find(t) == counts.end() || counts[t] == 0)
                {
                    break;
                }
                counts[t] -= 1;
            }

            if (i == L.size())
            {
                result.push_back(cur);
            }
        }

        return result;
    }
};

int main()
{
    Solution s;

    string S = "barfoothefoobarman";
    vector<string> L;
    L.push_back("foo");
    L.push_back("bar");

    vector<int> result = s.findSubstring1(S, L);
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << endl;
    }

    return 0;
}
