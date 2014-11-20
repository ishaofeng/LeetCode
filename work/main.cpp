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
#include <cstdlib>
using namespace std;


class Solution
{
public:
    int maxProfitHelp(vector<int> &prices, vector<int> &keep, int i, int stock)
    {
        if (i == (prices.size() - 1))
        {
            int money = stock > 0 ? prices[i] : 0;
            prices[i] = money;

            return money;
        }

        if (keep[i] > 0)
        {
            return keep[i];
        }


        int buy = 0, sell = 0, noop = 0;
        buy = maxProfitHelp(prices, keep, i + 1, stock + 1) - prices[i];
        if (stock > 0)
        {
            sell = maxProfitHelp(prices, keep, i + 1, stock - 1) + prices[i];
        }
        noop = maxProfitHelp(prices, keep, i + 1, stock);

        int money = max(buy, max(sell, noop));
        keep[i] = money;

        return money;
    }

    int maxProfit(vector<int> &prices)
    {
        vector<int> keep(prices.size(), -1);

        return maxProfitHelp(prices, keep, 0, 0);
    }
};

int main()
{
    Solution s;

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    cout << s.maxProfit(v) << endl;
}
