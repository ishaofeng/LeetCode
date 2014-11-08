#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cctype>

using namespace std;


class Solution
{
public:
    bool isPalindrome(string s)
    {
        if (s.empty())
        {
            return true;
        }

        int start = 0, end = s.size() - 1;

        while (start < end)
        {
            while (start < end && !isalnum(s[start]))
            {
                ++start;
            }

            while (start < end && !isalnum(s[end]))
            {
                --end;
            }

            if (start >= end)
            {
                break;
            }

            if (tolower(s[start]) != tolower(s[end]))
            {
                return false;
            }

            ++start;
            --end;
        }

        return true;
    }
};

int main()
{
    char dat[] = "l: Panama";
    Solution s;
    cout << s.isPalindrome(dat) << endl;
}
