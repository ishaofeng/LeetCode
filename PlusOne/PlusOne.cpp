#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> result;

        int len = digits.size();
        int plus = 0, plusstep = 1;
        for (int i = len - 1; i >= 0; --i)
        {
            plus = digits[i] + plusstep;
            if (plus >= 10)
            {
                plusstep = plus / 10;
                plus = plus % 10;
            }
            else
            {
                plusstep = 0;
            }

            result.insert(result.begin(), plus);
        }
        if (plusstep != 0)
        {
            result.insert(result.begin(), plusstep);
        }

        return result;
    }
};

int main()
{
    int A[] = {1, 1, 1, 2, 2, 2, 3, 4, 4};
    vector<int> digits(A, A + sizeof(A) / sizeof(A[0]));
    Solution s;
    vector<int> result = s.plusOne(digits);
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
