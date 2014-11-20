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
    vector<vector<int> > threeSum(vector<int> &num)
    {
        vector<vector<int> > result;
        if (num.size() < 3)
        {
            return result;
        }

        int target = 0;
        sort(num.begin(), num.end());

        int len = num.size();
        int over, sum;
        for (int i = 0; i < (len - 2); ++i)
        {
            if (i > 0 && num[i-1] == num[i])
            {
                continue;
            }

            over = target - num[i];
            int b = i + 1;
            int e = len - 1;
            int lastb, laste;
            bool bSet = false;
            while (b < e)
            {
                sum = num[b] + num[e];
                if (sum < over)
                {
                    ++b;
                }
                else if (sum > over)
                {
                    --e;
                }
                else
                {
                    if (bSet == false)
                    {
                        bSet = true;
                    }
                    else
                    {
                        if (lastb == num[b] && laste == num[e])
                        {
                            ++b;
                            continue;
                        }
                    }

                    vector<int> line;
                    line.push_back(num[i]);
                    line.push_back(num[b]);
                    line.push_back(num[e]);
                    lastb = num[b];
                    laste = num[e];
                    result.push_back(line);
                    ++b;
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution s;
//    int d[] = {-1, 0, 0, 0, 1, 2, -1, -4};
    int d[] = {0, 0, 0};
//    int d[] = {-479,-472,-457,-451,-439,-418,-395,-392,-387,-363,-342,-330,-323,-316,-301,-291,-227,-215,-192,-171,-168,-153,-141,-121,-111,-75,-71,-66,6,28,28,35,46,48,48,50,76,81,83,117,143,171,175,178,197,202,203,238,258,278,282,313,316,319,342,347,383,396,403,406,452,462,469,471,478};

    vector<int> data;
    for (int i = 0; i < (sizeof(d) / sizeof(d[0])); ++i)
    {
        data.push_back(d[i]);
    }
    vector<vector<int> > result = s.threeSum(data);
    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < result[i].size(); ++j)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
