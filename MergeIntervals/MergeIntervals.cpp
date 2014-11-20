#include <iostream>
#include <vector>
#include <set>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <algorithm>
using namespace std;


struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
class Solution
{
public:
    static bool intervalCmp(const Interval &a, const Interval &b)
    {
        return a.start < b.start;
    }

    vector<Interval> merge(vector<Interval> &intervals)
    {
        if (intervals.size() <= 1)
        {
            return intervals;
        }

        vector<Interval> result;
        sort(intervals.begin(), intervals.end(), intervalCmp);


        int start = intervals[0].start, end = intervals[0].end;

        for (int i = 1; i < intervals.size(); ++i)
        {
            Interval &interval = intervals[i];
            if (interval.start > end)
            {
                result.push_back(Interval(start, end));
                start = interval.start;
                end = interval.end;
            }
            else if (interval.end > end)
            {
                end = interval.end;
            }
        }
        result.push_back(Interval(start, end));

        return result;
    }
};

int main()
{
    int data[] = { 2, 3, 4, 5, 6, 1};
    vector<int> v(data, data + sizeof(data) / sizeof(data[0]));
    Solution s;
    string ss = "PAYPALISHIRING";
    int data1[][3] = {{1, 0, 0},
                      {0, 1, 0},
                      {2, 0, 3}};
    vector<vector<int> > vv;
    for (int i = 0; i < 3; ++i)
    {
        vector<int> line;
        for (int j = 0; j < 3; ++j)
        {
            line.push_back(data1[i][j]);
        }
        vv.push_back(line);
    }
    vector<Interval> intervals;
    intervals.push_back(Interval(1, 3));
    intervals.push_back(Interval(2, 6));
    intervals.push_back(Interval(8, 10));
    intervals.push_back(Interval(15, 18));
    intervals = s.merge(intervals);

    for (int i = 0; i < intervals.size(); ++i)
    {
        cout << intervals[i].start << " " << intervals[i].end << endl;
    }
}
