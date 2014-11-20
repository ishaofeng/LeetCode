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
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        if (a.first > b.first)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> result;
        if (numbers.size() < 2)
        {
            return result;
        }

        vector<pair<int, int> > infos;
        for (int i = 0; i < numbers.size(); ++i)
        {
            infos.push_back(make_pair(numbers[i], i));
        }
        sort(infos.begin(), infos.end(), cmp);

        sort(numbers.begin(), numbers.end());

        int b = 0;
        int e = numbers.size() - 1;
        int sum;
        while (b < e)
        {
            sum = numbers[b] + numbers[e];
            if (sum > target)
            {
                --e;
            }
            else if (sum < target)
            {
                ++b;
            }
            else
            {
                int ib = infos[b].second;
                int ie = infos[e].second;

                if (ib > ie)
                {
                    int tmp = ib;
                    ib = ie;
                    ie = tmp;
                }

                result.push_back(ib + 1);
                result.push_back(ie + 1);
                break;
            }
        }

        return result;
    }
};

int main()
{
    Solution s;
//    int d[] = {-1, 0, 0, 0, 1, 2, -1, -4};
    int d[] = {2, 7, 11, 15};
//    int d[] = {-479,-472,-457,-451,-439,-418,-395,-392,-387,-363,-342,-330,-323,-316,-301,-291,-227,-215,-192,-171,-168,-153,-141,-121,-111,-75,-71,-66,6,28,28,35,46,48,48,50,76,81,83,117,143,171,175,178,197,202,203,238,258,278,282,313,316,319,342,347,383,396,403,406,452,462,469,471,478};

    vector<int> data;
    for (int i = 0; i < (sizeof(d) / sizeof(d[0])); ++i)
    {
        data.push_back(d[i]);
    }
    vector<int> result = s.twoSum(data, 9);
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}
