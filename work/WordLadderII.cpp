#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict)
    {
        int wordlen = start.size();
        vector<set<char> > letters;
        auto beg = dict.begin();
        for (; beg != dict.end(); ++beg)
        {

        }
    }
};


int main()
{
}

