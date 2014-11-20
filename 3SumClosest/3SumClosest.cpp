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
    int twoSum(vector<int> &numbers, int target)
    {
        if (numbers.size() < 2)
        {
            return 0;
        }

        sort(numbers.begin(), numbers.end());

        int len = numbers.size();
        int closest = 1 << 21;
        int sum;
        for (int i = 0; i < (len - 2); ++i)
        {
            int b = i + 1;
            int e = numbers.size() - 1;
            while (b < e)
            {
                sum = numbers[b] + numbers[e] + numbers[i];
                if (abs(sum - target) < abs(closest - target))
                {
                    closest = sum;
                }

                if (sum > target)
                {
                    --e;
                }
                else
                {
                    ++b;
                }
            }
        }

        return closest;
    }
};

int main()
{
    Solution s;
//    int d[] = {-1, 0, 0, 0, 1, 2, -1, -4};
    int d[] = {0, 1, 2};
//    int d[] = {-479,-472,-457,-451,-439,-418,-395,-392,-387,-363,-342,-330,-323,-316,-301,-291,-227,-215,-192,-171,-168,-153,-141,-121,-111,-75,-71,-66,6,28,28,35,46,48,48,50,76,81,83,117,143,171,175,178,197,202,203,238,258,278,282,313,316,319,342,347,383,396,403,406,452,462,469,471,478};

    vector<int> data;
    for (int i = 0; i < (sizeof(d) / sizeof(d[0])); ++i)
    {
        data.push_back(d[i]);
    }
    int result = s.twoSum(data, 0);
    cout << result << endl;
}
