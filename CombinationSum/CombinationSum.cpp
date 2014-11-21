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
    void combinationSumHelp(vector<int> &candidates, int target, int start, vector<vector<int> > &result, vector<int> &line)
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


        combinationSumHelp(candidates, target, start + 1, result, line);

        line.push_back(candidates[start]);
        combinationSumHelp(candidates, target - candidates[start], start, result, line);
        line.pop_back();
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());

        vector<vector<int> > result;
        vector<int> line;

        combinationSumHelp(candidates, target, 0, result, line);

        return result;
    }
};

int main()
{
    Solution s;

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    vector<vector<int> > result = s.combinationSum(v, 7);
    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < result[i].size(); ++j)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
