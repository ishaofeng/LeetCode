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
#include <queue>
#include <cstdlib>
using namespace std;

class Solution
{
public:
    void combinationSumHelp(vector<int> &candidates, int target, int start, vector<vector<int> > &result, vector<int> &line, unordered_map<int, int> &m)
    {
        if (target < 0)
        {
            return ;
        }
        if (target == 0)
        {
            result.push_back(line);
            return ;
        }

        int len = candidates.size();
        if (start >= len)
        {
            return ;
        }


        combinationSumHelp(candidates, target, start + 1, result, line, m);

        if (m[candidates[start]] > 0)
        {
            m[candidates[start]]--;
            line.push_back(candidates[start]);
            combinationSumHelp(candidates, target - candidates[start], start, result, line, m);
            line.pop_back();
            m[candidates[start]]++;
        }

    }
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target)
    {
        unordered_map<int, int> m;
        vector<int> v;
        for (int i = 0; i < candidates.size(); ++i)
        {
            if (m.find(candidates[i]) == m.end())
            {
                m[candidates[i]] = 0;
                v.push_back(candidates[i]);
            }

            m[candidates[i]]++;
        }

        sort(v.begin(), v.end());

        vector<vector<int> > result;
        vector<int> line;

        combinationSumHelp(v, target, 0, result, line, m);

        return result;
    }
};

int main()
{
    Solution s;

    vector<int> v;
    v.push_back(10);
    v.push_back(1);
    v.push_back(2);
    v.push_back(7);
    v.push_back(6);
    v.push_back(1);
    v.push_back(5);

    vector<vector<int> > result = s.combinationSum2(v, 8);
    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < result[i].size(); ++j)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
